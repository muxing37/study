# Linux一些常用命令
## 一、文件与目录管理（最核心）
- 1.<kbd>ls</kbd> —— 列出目录内容
<kbd>ls -a</kbd> 显示所有文件
<kbd>ls -l</kbd> 以长格式显示详细信息
<kbd>ls -lh</kbd> 长格式显示，文件大小以易读的单位(如K,M,G)显示
<kbd>ls -R</kbd> 递归列出所有子目录的内容
- 2.<kbd>cd</kbd> —— 切换目录
<kbd>cd .\.</kbd> 切换到上一级目录(父目录)
<kbd>cd ~</kbd> 切换到当前用户的家目录(通常是/home/用户名)
<kbd>cd -</kbd> 切换到上一次所在的工作目录
- 3.<kbd>pwd</kbd> —— 显示当前路径
- 4.<kbd>cp</kbd> —— 复制
<kbd>cp a b</kbd> 将文件 a 复制到文件 b
<kbd>cp -r dir1 dir2</kbd> 递归复制整个目录
<kbd>cp -a src dst</kbd> 归档模式复制，保留文件的所有属性
- 5.<kbd>mv</kbd> —— 移动/重命名
<kbd>mv a b</kbd> 如果b不存在，将a重命名为b
如果b是一个存在的文件，用a的内容覆盖b的内容
如果b是一个存在的目录，将 a移动到b目录内
- 6.<kbd>rm</kbd> —— 删除
<kbd>rm -r dir</kbd> 递归删除目录dir及其所有内容
<kbd>rm -rf dir</kbd> 强制递归删除目录dir
- 7.<kbd>mkdir/rmdir</kbd> —— 创建/删除目录
## 二、文件内容查看与处理
- 1.<kbd>cat</kbd> —— 连接文件并打印到标准输出
<kbd>cat file</kbd> 在终端显示文件file的全部内容
<kbd>cat -n file</kbd> 在终端显示文件file的内容，并显示行号
- 2.<kbd>less / more</kbd> —— 分页查看文件内容
<kbd>more file.txt</kbd> 分页查看，功能相对较少
<kbd>less file.txt</kbd> 高级分页查看，more的增强版
- 3.<kbd>head / tail</kbd> —— 查看文件开头/结尾部分(默认显示10行)
<kbd>head -20 test.txt</kbd> 查看文件前20行
<kbd>tail -f /var/log/syslog</kbd> 实时监控系统日志
- 4.<kbd>wc</kbd> —— 统计文件中的字节数、单词数、行数
<kbd>wc file</kbd> 统计文件file的行数、单词数、字节数
<kbd>wc -l file</kbd> 只统计文件file的行数
## 三、权限与属性
- 1.<kbd>chmod</kbd> —— 改变文件或目录的权限
<kbd>chmod 755 file</kbd> 使用数字模式设置文件的权限为755
权限的数字表示：4=r(读)、2=w(写)、1=x(执行)、0=无权限
第一个数字 7：文件所有者(u)的权限=4(r)+2(w)+1(x)=rwx
第二个数字 5：文件所属组(g)的权限=4(r)+1(x)=r-x
第三个数字 5：其他用户(o)的权限=4(r)+1(x)=r-x
<kbd>chmod u+x file</kbd> 使用符号模式给文件所有者(u)添加执行权限(x)
- 2.<kbd>chown / chgrp</kbd> —— 修改文件所有者和所属组
<kbd>chown alice file.txt</kbd> 将file.txt的所有者改为alice
<kbd>chown alice:developers file.txt</kbd> 所有者改为alice组改为developers
<kbd>chgrp</kbd> 只修改文件所属组
- 3.<kbd>stat</kbd> —— 显示文件或文件系统的详细状态
<kbd>stat file</kbd> 显示文件file的详细状态信息
# 四、进程与系统状态
- 1.<kbd>top</kbd> —— 实时显示系统进程和资源使用情况
<kbd>top -d 1</kbd> 设置刷新间隔为1秒
- 2.<kbd>kill</kbd> —— 向进程发送信号
<kbd>kill pid</kbd> 向进程ID为pid的进程发送默认信号SIGTERM(15)（终止信号，要求进程正常退出）
<kbd>kill -9 pid</kbd> 向进程ID为pid的进程发送信号SIGKILL (9)（强制终止信号，立即杀死进程）