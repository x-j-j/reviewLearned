1.用metasploit-framework/tools/exploit# ./pattern_create.rb

metasploit-framework/tools/exploit# ./pattern_offset.rb 39694438

测试溢出的位置

2.找坏字符

3.用msfpayload生成win_reverse shellcode 使用msfencode -b去掉坏字符

4.