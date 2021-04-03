`项目`里面是项目的代码  
`网址.md`网址里面填着复习的网站  
`简历.docx`里是我简历  

为了通过字节跳动的安全岗面试,我决定练习先讲出来，然后再写出来，这是最后一次，没有下次。
知识点概括，先自己练习讲出来并录音。

# sql注入：
1.盲注：布尔，时间  
    盲注是页面没有回显情况下的注入。布尔盲注通过判断成立还是不成立进行回显，时间盲注通过延时判断相应语句是否执行。    
2.报错注入  
    报错注入是通过注入非法sql语句，让数据库报错回显到页面，然后获取信息的一种注入。    
3.堆叠注入  
    使用mysqli_multi_query()函数，此函数可以执行多条sql语句，以分号分割    
4.二次注入  
    本质是程序员信任数据库中的数据，拿出来使用没有进行过滤。比如注册admin'#用户虽然有\转译'但是插入数据库时没有\。读出来就是admin'#所以当此用户再拼接数据库时会直接操作admib用户  
5.宽字节注入  
    数据库端使用GBK编码，%df开头的连续两个字符变成汉字。输入%df'经过后台过滤变成%df\'到数据库变成[某个汉字]'进行绕过    
6.联合注入  
    使用union select联合查询进行注入,前后select字段数要相同。通常会查询information_schema数据库获取数据    
7.limit,order by注入  
    order by可基于if，基于时间(成倍)，基于rand盲注(false排序正常，true随机排序)，也可报错注入  
8.用到的函数    
    updatexml(),extractvalue()  
    sleep(),if()  
    mid(),substr(),left(),length()  
    concat(),group_concat()  
    count(),floor(),rand()  
    ord(),char(),ascii()  
9.sql注入getshell   
    select '' into outfile '';  
10.sqlmap使用--current-db    
11.防注入  
    mysql_real_escape_string()  
    addslashes()  
    PDO  



# XSS
本质上两种，反射型，存储型。dom型属于反射型，只不过是纯前端的xss。   
存储型：文本框,留言等  
反射型：社工，发链接诱惑点击  
利用：1.x cookie  
      2.弹窗钓鱼获取账号密码  
      3.流量接触恶意跳转  
      4.xss中使用csrf  
csp  
csp中文名称是内容安全策略，他限制页面资源的加载，从而避免xss  
他可以再meta标签里编辑，也可以再http报文的header中编辑  
写法上比如script-src 'self'意思是只能使用本域下的js资源，外部引进的不会执行(xss alert也不会执行))  
script-src 'unsafe-inline'就可执行xss alert但是不能引进外部数据  
但是  
1.过滤的不全会被绕过,比如object标签也可执行js，  
2.允许unsafe-inline或者data协议也会被绕过  
3.script列表包含不安全的库也会被绕过，some攻击  
所以最保险的是使用default标签，只允许从特定网站加载资源  

# Upload
文件上传漏洞，指可以上传非法后缀名的文件从而getshell
绕过姿势：
后缀绕过
MIME+文件幻数绕过
图片马+文件包含绕过
中间件绕过
条件竞争绕过

# SSRF
# CSRF
# XXE
