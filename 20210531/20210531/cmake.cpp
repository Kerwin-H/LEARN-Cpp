
//cmake�ײ�ʵ��,����ֲ�����
cmake_minimum_required(VERSION 2.8)
project(main)

#���ñ���ѡ��
set(CMAKE_CXX_FLAGS ${ CMAKE_CXX_FLAGS } -g)

#����ͷ�ļ�����·��
#include_directories()

#���ÿ��ļ�����·��
#link_directories()

#������Ҫ�����Դ�ļ��б�
set(SRC_LIST muduo_server.cpp)

#���ÿ�ִ���ļ����յĴ���·��
set(EXECUTABLE_OUTPUT_PATH ${ PROJECT_SOURCE_DIR } / bin)

#��ָ��·���µ�����Դ�ļ����ַ���SRC_LIST��
#aux_source_directory(.src_list)

#���ɿ�ִ���ļ�server, ��SRC_LIST���������Դ�ļ��������
add_executable(server ${ SRC_LIST })

#��ʾserver���������Ҫ�������������ļ�
target_link_libraries(server muduo_net muduo_base pthread)



//�ⲿ��������
cmake_minimum_required(2.8)
project(main)


#���ñ���ѡ��
set(CMAKE_CXX_FLAGS ${ CMAKE_CXX_FLAGS } -g)

#ָ����������Ŀ¼�µ�CMakeLists.txt
add_subdirectory(testmuduo)