# -socket
9-7 linux C语言环境下（32位） socket

环境：虚拟机，最好可以进行文件的共享，或主机与虚拟机之间文件的复制黏贴


Linux C语言：准备32位运行环境 参考：https://blog.csdn.net/qq_41725312/article/details/90729247


远程连接：xshell && vscode（远程代码编辑）


socket知识点：https://blog.csdn.net/PinkBean/article/details/71108622

TCP/UCP的通信代码区别 流程区别 https://blog.csdn.net/e21105834/article/details/91494918

关于如何判断大段，小端的方法：https://blog.csdn.net/sustzc/article/details/80151244 
思路：对于整形数字1 四个字节char，是被存储在高地址-大端，还是低地址-小端，当前系统为大端存储模式时，其低地址处存储 00，而当前系统为小端存储模式时，其低地址处存储 01。
