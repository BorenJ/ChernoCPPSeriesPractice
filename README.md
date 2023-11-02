# 运行文件
运行系统是Ubuntu，用VSCode 在ros功能包下，需要配置CMakelist。 
- **1. 在linux上下载VSCode**。
- **2. 创建工作空间**。打开终端 `Ctrl + Alt + T`, 输入
	```
	mkdir -p xxxws/src
	cd xxxws
	catkin_make
	code .
	```
- **3. 快捷键 `Ctrl + Shift + B` 调用编译**。点击`catkin_make:build` 右侧的齿轮，修改xxxws/vscode/tasks.json 文件, 删除原文件内容，将以下内容复制进原文件。For more details, please see [VSCode配置教程](http://www.autolabor.com.cn/book/ROSTutorials/chapter1/14-ros-ji-cheng-kai-fa-huan-jing-da-jian/142-an-zhuang-vscode.html)
	```
	{
	// 有关 tasks.json 格式的文档，请参见
	    // https://go.microsoft.com/fwlink/?LinkId=733558
	    "version": "2.0.0",
	    "tasks": [
	        {
	            "label": "catkin_make:debug", //代表提示的描述性信息
	            "type": "shell",  //可以选择shell或者process,如果是shell代码是在shell里面运行一个命令，如果是process代表作为一个进程来运行
	            "command": "catkin_make",//这个是我们需要运行的命令
	            "args": [],//如果需要在命令后面加一些后缀，可以写在这里，比如-DCATKIN_WHITELIST_PACKAGES=“pac1;pac2”
	            "group": {"kind":"build","isDefault":true},
	            "presentation": {
	                "reveal": "always"//可选always或者silence，代表是否输出信息
	            },
	            "problemMatcher": "$msCompile"
	        }
	    ]
	}
	```
- **4. 在工作空间创立功能包**。在VSCcode左侧栏`xxxws`目录下右键`src`，选择`Creat Catkin Package`，先输入功能包名称，此处为`Practice`，然后`回车`，再输入依赖，此处为`roscpp rospy std_msgs`。
- 在功能包目录`Practice/src`下中粘贴本项目`.cpp`文件。
- **5. 修改CMakeist.txt**。注意此文件目录是`xxxws/src/Practice/CMakelist.txt。以P45_smart_pointer.cpp 为例。在CMakelist.txt添加
	```
	add_executable(P45 src/P45_smart_pointer.cpp)

	target_link_libraries(P45
	${catkin_LIBRARIES}
	)
	```
	在add_executable中，`P45` 是 CMake 目标名称，`src/P45_smart_pointer.cpp`是`.cpp`文件在功能包目录的名称。在target_link_libraries中，`P45` 是 CMake 目标名称，名称要与add_executable一致。如果有多个可执行文件`.cpp`，则如下
	```
	add_executable(P45 src/P45_smart_pointer.cpp)
	add_executable(P47 src/P47_dynamic_array.cpp)
	add_executable(P48 src/P48_stdvec_optimize.cpp)
	...

	target_link_libraries(P45
	${catkin_LIBRARIES}
	)
	target_link_libraries(P47
	${catkin_LIBRARIES}
	)
	target_link_libraries(P48
	${catkin_LIBRARIES}
	)
	...
	```
- `Ctrl + Shift + B` 编译文件。
- **6. 运行可执行文件**。`Ctrl + ~ ` 调用VSCode终端，目录应该在xxxws下，输入`source ./devel/setup.bash`，回车。输入`rosrun practice P45`即可运行。
