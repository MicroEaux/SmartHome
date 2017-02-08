# SmartHome
基于 ESP8266 的智能家居解决方案
2017/02/08 - 0
	添加 ESP8266_RTOS_SDK-master 版本V1.5.0 工程文件
2017/02/08 - 1
	1.复制 [SDK] \examples\project_template 下的 project_template 到 [SDK] \ 下，并重命名为 app
	2.备份移除目录 [SDK] \ 下的 documents、driver_lib、examples 三个目录，仅留下必要工程文件
	3.移除目录 app 下的 sample_lib 目录
	4.复制 gen_misc.sh 为 compile_gen_misc.sh
	5.修改compile_gen_misc.sh
	6.修改Makefile
