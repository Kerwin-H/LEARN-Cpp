
//cmake底层实现,具体分布操作
cmake_minimum_required(VERSION 2.8)
project(main)

#配置编译选项
set(CMAKE_CXX_FLAGS ${ CMAKE_CXX_FLAGS } -g)

#配置头文件搜索路径
#include_directories()

#配置库文件搜索路径
#link_directories()

#设置需要编译的源文件列表
set(SRC_LIST muduo_server.cpp)

#设置可执行文件最终的储存路径
set(EXECUTABLE_OUTPUT_PATH ${ PROJECT_SOURCE_DIR } / bin)

#把指定路径下的所有源文件名字放入SRC_LIST中
#aux_source_directory(.src_list)

#生成可执行文件server, 由SRC_LIST变量定义的源文件编译而来
add_executable(server ${ SRC_LIST })

#表示server这个程序需要连接这三个库文件
target_link_libraries(server muduo_net muduo_base pthread)



//外部代码配置
cmake_minimum_required(2.8)
project(main)


#配置编译选项
set(CMAKE_CXX_FLAGS ${ CMAKE_CXX_FLAGS } -g)

#指定搜索的子目录下的CMakeLists.txt
add_subdirectory(testmuduo)