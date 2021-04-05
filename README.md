`项目`里面是项目的代码  
`网址.md`网址里面填着复习的网站  
`简历.docx`里是我简历  

知识点概括，先自己练习讲出来录音然后写出来。

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
    写日志   
10.sqlmap使用--current-db    
11.防注入  
    mysql_real_escape_string()  
    addslashes()  
    PDO  

# waf绕过
waf中文名称是web应用防火墙分为硬件防火墙，软件防火墙，云防火墙
1.函数过滤替换(首先爆破观察那种函数可使用再进行重组替换)
select mid(user(),1,2);  =>  select substr(user() from 1 for 2);  =>  replace(LPAD(user(),2,1),LPAD(user(),2-1,1),"");
ord => conv(hex(),16,10);
2.逗号过滤绕过(fromfor, offset, join)
`select mid(user() from 1 for 2);`  
`if(,,) => case when`  
`select 1,2  =>  select * from (select 1)a join (select 2)b;`  
`limit 2,1  =>  limit 1 offset 2;`  
3.空格过滤绕过(注释，括号)  
`select/**/1/**/from/**/1;`    
`select(user());`  
4.引号过滤绕过(16进制)  
引号中的内容用16进制表示
5.大小写，双写
6.=过滤绕过
between 1 and 1等价于1


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
1.过滤的不全会被绕过,比如object标签也可加载远程代码，  
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
ssrf(server-side resource forgray)的中文名称是服务端请求伪造,他是由攻击者构造的由服务器发起请求的安全漏洞,一般应用于无法从外网访问的内部系统
产生原因呢是，他提供了从其他服务器获取资源的功能，但是没有对目标地址进行过滤
如何确认是否具有ssrf漏洞呢,在他访问外网资源的url处填写其他地址，比如自己vps上的一个文件或者127.0.0.1下的某个文件
利用方式很多种，常用一些协议,file,gopher,dict,ftp
绕过也有一些技巧ip写成16进制，dns范域名xip.io，缩写等

# CSRF  
csrf的中文名称是跨站请求伪造。他原理就是盗用你的身份，发送恶意请求
道理都懂
反射型xss和csrf的区别：xss是盗取受害者的cookie，csrf是利用受害者直接完成相应操作

csrf防护，Token的位置: 
1.cookie中。并且用户发送http时要求token相同
2.接着a或者form标签隐藏token
token绕过：
1.点击劫持(目标网站在顶层隐藏，底层显示其他信息诱惑用户点击)
2.更改请求方法


# XXE  
xml外部实体注入漏洞，XXE漏洞发生在应用程序解析XML输入时，没有禁止外部实体的加载，导致可加载恶意外部文件，造成文件读取、命令执行、内网端口扫描、攻击内网网站、发起dos攻击等危害。
xxe漏洞触发的点往往是可以上传xml文件的位置，没有对上传的xml文件进行过滤，导致可上传恶意xml文件。  
用system调用外部实体，实现文件读取文件调用,ssrf,dos攻击等等。


# 同源策略  
限制不同源之间的资源访问  
同源的概念是协议，域名，端口都相同  
限制cookie访问，ajax，iframe窗口与父窗口无法通信  
# cors  
cors的全称是跨域资源共享,是为了克服ajax只能同域请求资源的限制  
当跨域请求的时候，header头会自动添加Origin字段，显示请求源  
回应方如果同意请求，会返回带有access-control-allow-origin字段的信息，里面添加的是origin字段  
如果回应放不同意，就不返回上面的字段，请求方直接抛出异常  
对于DELETE或者PUT等特殊请求的跨域时，会先发送一个预请求，询问是否支持特殊方法。  

# redis漏洞  
未授权访问  
1.getshell  
config set dir /var/www    
2.写入计划任务  
/var/spool/cron  
3.ssh写公钥  
/root/.ssh写入公钥  
# mysql提权  
mof  
系统每隔一段时间执行一次C:/Windows/system32/wbem/mof/的mof文件，mysql能够操作此文件即可进行提权   
udf  
用户自定义函数进行提权    
1.寻找动态链接库udf.dll(sqlmap,metasploit自带)  
2.寻找mysql插件目录  
3.想办法把文件动态链接库放到插件目录  
4.创建自定义函数  
5.执行系统命令  



# oracle  



# git  
git他是一个分布式版本控制的工具，意思是他可以分布式管理多人协作，也有版本控制的机制  
git的结构是工作区->暂存区->远程仓库  
git有分支管理的机制,可创建删除分支,也可将分支和master合并  
版本控制的原理是通过指针head指向master,master指向最后一次commit.通过修改master指针，指向任意历史节点  
git add -> 保存对象更新暂存区  
git commit -> 写入历史信息，生成版本快照  

# docker  
虚拟化技术
网络隔离: 当在一个端口启动了某个docker服务的时候iptables会设置规则，所有经过这个端口的tcp都要转发给docker的内部端口
文件系统隔离: chroot
进程隔离: 虚拟机开启全新的进程，与主机隔离
物理资源隔离:  cgroup
采用分层的概念，和多层复用机制
容器和镜像的区别就在于，所有的镜像都是只读的，而每一个容器其实等于镜像加上一个可读写的层，也就是同一个镜像可以对应多个容器。
结构大概是：最底层是kernel，上层是多个只读的镜像层组装，最上层是用户可控的容器层

# 缓冲区溢出  
# Linux内网  
# 中间件  
iis6.0:  
1.PUT漏洞: 开启webdav和写权限导致使用put可写入任意文件  
2.短文件名猜解: 暴力猜测文件名404存在，400不存在  
3.远程代码执行: 栈溢出  
4.文件/目录解析漏洞: asp目录下的文件都变成asp文件  /test.asp/test.jpg   test.asp;.jpg   从左侧找，先找. => 找;截断 =>找/截断  
iiS7.5:  
畸形解析漏洞: test.jpg/.php  给php并依次删掉/后面的直到存在文件  
apache:  
解析漏洞: 从又向左找可解析的后缀  
目录遍历: 配置问题  
nginx  
畸形解析:   
目录遍历: 配置  
CRLF: 配置  

# 网络协议
1.三次握手与四次挥手
2.https建立过程
3.签名，摘要
4.怎么验证证书


# 多线程多进程
多生产者多消费者
线程安全




# python语言特性
1.cpython中的gil
为了利用多核，Python开始支持多线程。而解决多线程之间数据完整性和状态同步的最简单方法自然就是加锁。 于是有了GIL这把超级大锁
但当CPU有多个核心的时候，问题就来了。从伪代码可以看到，从release GIL到acquire GIL之间几乎是没有间隙的。所以当其他在其他核心上的线程被唤醒时，大部分情况下主线程已经又再一次获取到GIL了。这个时候被唤醒执行的线程只能白白的浪费CPU时间，看着另一个线程拿着GIL欢快的执行着。然后达到切换时间后进入待调度状态，再被唤醒，再等待，以此往复恶性循环。
用multiprocessing替代Thread,每个进程有自己的独立的GIL，因此也不会出现进程之间的GIL争抢

2.从操作系统层面讲进程与线程区别
进程有独立的地址空间，一个进程崩溃后，在保护模式下不会对其它进程产生影响，而线程只是一个进程中的不同执行路径。线程有自己的堆栈和局部变量，但线程之间没有单独的地址空间，一个线程死掉就等于整个进程死掉，所以多进程的程序要比多线程的程序健壮，但在进程切换时，耗费资源较大，效率要差一些。但对于一些要求同时进行并且又要共享某些变量的并发操作，只能用线程，不能用进程。

3.线程安全
dict线程安全,原子操作
Queue线程安全
list有些操作不安全
根本原因是字节码操作是只有一条还是多条

4.线程间的通信
Event
Condition
Queue

# nmap使用和dos攻击
客户端向服务端发送带有 PSH，FIN，URG 标识和端口号的数据包，如果端口开放，则服务端不会有任何的响应。而如果服务端返回来一个 RST 数据包，则表明端口处于关闭状态。
空扫描类似fin扫，只不过发送的flag是空
ack扫是确定是否有防火墙，返回rst无防火墙，返回icmp有防火墙
tcp cookie/syn cookie  来解决syn dos原理是不分配资源的情况下判断后续ack到达的可能性

# 钓鱼网站识别
观察域名
查看源代码逻辑
查询钓鱼网站的whois信息
查询网站备案
一般直接让输入用户名密码的都得提防


# 算法数据结构
1.数组与链表的优缺点
数组随机访问性强，占用内存小
链表增删改强


## 快排
`
void quickSort(int arr[], int low, int high){
    qsort(arr, low, high);
}
void qsort(int arr[], int low, int high){
    if (low >= high){
        return;
    }
    int k = partition(arr, low, high);
    qsort(arr, low, k-1);
    qsort(arr, k+1, high);
}
int partition(int arr[], int low, int high){
    int k = arr[low];
    while(low < high){
        while(low < high && arr[high]>=k) high--;
        while(low < high && arr[low]<=k) low++;
        swap(arr[low], arr[high]);
    }
    arr[low] = k;
    return low;
}
`
## 归并排序
`
void mergeSort(int arr[]){
    int * temp = new int[arr.length];
    internalMergeSort(arr, tmp, 0, arr.length-1);
}
void internalMergeSort(int []arr, int []tmp, left, right){
    if (left < right){
        middle = (left + right)/2;
        internalMergeSort(arr, tmp, left, middle);
        internalMergeSort(arr, tmp, middle+1, right);
        merge(arr, tmp, left, middle, right);
    }
}
void merge(int[] arr, int[] tmp, int left, int middle, int right){
    int i = left;
    int j = middle+1;
    int k = 0;
    while(i<=middle && j<=right){
        tmp[k++] = arr[i]<=arr[j] ? arr[i++] : arr[j++];
    }
    while(i<=middle){
        tmp[k++]=arr[i++];
    }
    while(j<=middle){
        tmp[k++]=arr[j++];
    }
    for(i = 0; i < k; ++i){
        arr[left + i] = tmp[i];
    }
}
`


# 问面试官的问题
1.我这个岗位以后的工作内容大概是什么，对于能力提升和知识获取帮助大吗
2.实际工作中和乙方差别大吗
3.web安全前景好吗，会在几年后饱和吗，所有的安全里面那个前景是最好的。
