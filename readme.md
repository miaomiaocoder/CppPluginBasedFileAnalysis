# 基于插件框架结构的文件统计分析软件

### 简介

使用c++实现基于插件框架结构的文件统计分析软件。本科大三期间完成，使用cmake构建，插件通过动态链接库实现。


### 开发环境

* debian linux环境

### 编译

* 构建系统选择 cmake version >= 3.0
* g++编译器 or clang++编译器 

### 目录

* finalVersion
    * 最终版本
    * [run.sh](finalVersion/run.sh) 
        - 使用脚本控制cmake构建
            ```sh
            rm -rf build plugin
            mkdir build
            cd build
            cmake ..
            make
            ```
    * [clean.sh](finalVersion/clean.sh)  
        - 对 cmake 产生的文件 clean
            ```
            rm -rf build plugin
            ```
    * [CMakeLists.txt](finalVersion/CMakeLists.txt)
    * [IPlugin.h](finalVersion/IPlugin.h)
    * [Line.cpp](finalVersion/Line.cpp)
    * [Word.cpp](finalVersion/Word.cpp)
    * [Size.cpp](finalVersion/Size.cpp)
    * [SuffixL.cpp](finalVersion/SuffixL.cpp)
    * [SuffixS.cpp](finalVersion/SuffixS.cpp)
    * [SuffixW.cpp](finalVersion/SuffixW.cpp)
    * main.cpp
    * SearchPlugin.cpp
    * SearchPlugin.h
    * CPluginController.cpp
    * CPluginController.h

* version1
    * [run.sh](version1/run.sh) 使用脚本控制cmake构建
    * [clean.sh](version1/clean.sh)  对 cmake 产生的文件 clean
    * [makefile](version1/makefile) 使用 makefile 演示编译程序
    * [CMakeLists.txt](version1/CMakeLists.txt) 
    * a.h
    * a1.cpp
    * a2.cpp
    * main.cpp
* version2
    * [run.sh](version2/run.sh) 使用脚本控制cmake构建
    * [clean.sh](version2/clean.sh)  对 cmake 产生的文件 clean
    * [CMakeLists.txt](version2/CMakeLists.txt) 
    * a.h
    * a1.cpp
    * a2.cpp
    * main.cpp
    * SearchPlugin.cpp
    * SearchPlugin.h
* version3
    * run.sh
        - 使用脚本控制cmake编译
    * clean.sh 
        - 对 cmake 产生的文件 clean
    * [CMakeLists.txt](version3/CMakeLists.txt) 
    * a.h
    * a1.cpp
    * a2.cpp
    * main.cpp
    * SearchPlugin.cpp
    * SearchPlugin.h
* version4
    * run.sh 
        - 使用脚本控制cmake构建
    * clean.sh 
        - 对 cmake 产生的文件 clean
    * [CMakeLists.txt](version4/CMakeLists.txt) 
    * IPlugin.h
    * a1.cpp
    * a2.cpp
    * main.cpp
    * SearchPlugin.cpp
    * SearchPlugin.h
    * CPluginController.cpp
    * CPluginController.h
* version5
    * run.sh
        - 使用脚本控制cmake构建
    * clean.sh  
        - 对 cmake 产生的文件 clean
    * [CMakeLists.txt](version5/CMakeLists.txt) 
    * IPlugin.h
    * Byte.cpp
    * Line.cpp
    * main.cpp
    * SearchPlugin.cpp
    * SearchPlugin.h
    * CPluginController.cpp
    * CPluginController.h


## 版本一
_版本1：_
* 开发一个程序，向屏幕打印“Hello World”；
* 在不重新编译链接原程序的前提下，将打印的文字改为“Hello China”

_提示：_
* 使用动态链接库实现打印功能

## 版本二
_版本2：_
* 同时要打印“Hello World”，打印“Hello China”，甚至同时打印未来才会增加的其他打印信息
* 打印未来的这些信息，也不能重新编译链接原程序

_提示_
* 一种打印功能用一个动态链接库（插件）实现
* 将这些插件放置在固定的目录中，例如当前的plugin目录
* 遍历这个目录，获取所有动态链接库

## 版本三
_版本3：_
* 版本2是同时调用所有插件的打印功能，现在要求一次只调用一种功能

_提示_
* 3-1：通过命令行方式：./a.out help，输出所有插件实现的功能ID，以及该功能ID对应的功能描述
* 3-2：通过命令行方式：./a.out FuncID，调用具体打印功能（每个插件导出GetID接口）

## 版本四
_版本4：_
* 在版本3中，插件导出了Print、GetID、Help三个函数，主程序需要使用多个容器分别保存这些函数地址
* 在复杂的业务逻辑中，导出的函数可能更多，若还按照版本3的方式，代码维护性不佳

_提示：_
* 将三个导出函数都放在一个类中，让插件外部获取该类的对象

## 版本五
_版本5：_
实现一个软件系统，该系统可对文件进行统计分析。究竟对文件进行什么样的统计分析，最终用户自己也不是很清楚，目前只知道需要统计文件的行数。也就是说，本软件系统将会随时面临，增加文件统计新功能的难题。设计并实现这样一个面向文件统计功能的插件系统。

（需要实现的插件包括：统计某个文件的行数，统计某个文件的字节数）

## 插件系统最终版本
_最终版本：_
#### 以插件的形式，实现若干文件统计分析功能。需要实现的功能至少包括：
 1.统计指定的某个文件的行数   
 2.统计指定的某个文件的单词数     
 3.统计指定目录下、特定后缀名的所有文件的行数。   
 4.每项功能使用单独的一个插件实现      
#### 其它要求：    
1.被统计的文件使用ASCII编码      
2.使用方式：插件框架程序需要处于一个循环中，不停地接收用户发来的命令（不能使用命令行参数，指定要执行的插件功能及其参数）

#### 我的插件
* 插件1：统计指定的某个文件的行数
* 插件2：统计指定的某个文件的单词数
* 插件3：统计指定目录下、特定后缀名的所有文件的行数。
* 插件4：统计指定目录下、特定后缀名的所有文件的单词数。
* 插件5：统计指定的某个文件的大小(字节数)
* 插件6：统计指定目录下、特定后缀名的所有文件的大小(字节数)

实现插件1：读取换行符，数量+1即可    
关键代码如下：
```cpp
virtual void Func(char *File)  //统计文件行数
{
    int fd;
    char temp;
    int num = 0;
    if (-1 == (fd = open(File, O_RDONLY)))  //只读方式打开文件
    {
        cout << "Can not open: " << File << endl;
        return;
    }
    while (read(fd, &temp, 1)) {
        if (temp == '\n')  //每次读到换行符num++
        {
            num++;
        }
    }
    close(fd);                                 //关闭文件
    cout << File << " line: " << num << endl;  //展示
}
```
实现插件2：先写一个统计每行单词数的函数，通过把每行的单词数加起来来统计文件的单词总数        
关键代码如下：
```cpp
int FuncLine(const char *szLine)  //统计每行单词数
{
    int nWords = 0;
    int i = 0;
    for (; i < strlen(szLine); i++) {
        if (*(szLine + i) != ' ') {
            nWords++;
            while ((*(szLine + i) != ' ') && (*(szLine + i) != '\0')) {
                i++;
            }
        }
    }
    return nWords;
}
void Func(char *File)  //统计文件单词数
{
    int nWords = 0;         //词计数变量，初始值为0
    FILE *fp;               //文件指针
    char carrBuffer[1024];  //每行字符缓冲，每行最多1024个字符
    if ((fp = fopen(File, "r")) == NULL)  //打开文件
    {
        cout << "fopen error" << endl;
        exit(-1);
    }
    while (!feof(fp))  //如果没有读到文件末尾
    {
        //从文件中读一行
        if (fgets(carrBuffer, sizeof(carrBuffer), fp) != NULL)
            //统计每行词数
            nWords += FuncLine(carrBuffer);
    }
    fclose(fp);  //关闭文件
    cout << "word numbers: " << nWords << endl;
}
```
实现插件3：关键在于在递归查找目录下每一个文件的过程中，匹配文件后缀名是否与特定后缀名相同，匹配成功调用函数打印该文件行数
获取文件后缀名的代码：
```cpp
string suffixStr = filename.substr(filename.find_last_of('.') + 1);//获取文件后缀
```   
关键代码如下：
```cpp
virtual void Func(char *File)  //统计文件行数
{
    int fd;
    char temp;
    int num = 0;
    if (-1 == (fd = open(File, O_RDONLY)))  //只读方式打开文件
    {
        cout << "Can not open: " << File << endl;
        return;
    }
    while (read(fd, &temp, 1)) {
        if (temp == '\n')  //每次读到换行符num++
        {
            num++;
        }
    }
    close(fd);                                 //关闭文件
    cout << File << " line: " << num << endl;  //展示
}
virtual void Func(string path, string suffix) {
    DIR *dir;
    struct dirent *ptr;
    if ((dir = opendir(path.c_str())) == nullptr) {
        perror("Open directory error...");  //打开目录文件失败
        exit(1);
    }
    while ((ptr = readdir(dir)) != nullptr)  //用readdir读取DIR dir结构体
    {
        if (strcmp(ptr->d_name, ".") == 0 ||
            strcmp(ptr->d_name, "..") == 0)  //跳过. 和 ..文件
            continue;
        else if (ptr->d_type == 8) {
            string filename = ptr->d_name;  //转换为 string
            string suffixStr =
                filename.substr(filename.find_last_of('.') + 1);  //获取文件后缀
            if (suffixStr == suffix)                              //匹配后缀
            {
                // files.push_back(path + "/" + ptr->d_name);
                char p[100];
                strcpy(p, (path + "/" + ptr->d_name).c_str());
                Func(p);  //调用函数打印该文件行数
            }
        } else if (ptr->d_type == 4)  // directory
        {
            Func(path + "/" + ptr->d_name, suffix);  //递归
        }
    }
    closedir(dir);  //关闭流
}
```
实现插件4：与实现3类似，只是把调用的函数换成打印文件单词数的函数即可。 

实现插件5：统计文件大小，又因为我们假设了被统计的文件使用ASCII编码，而一个字符的ASCII码占用存储空间为1个字节，所以统计字符数即可获得文件大小。    
关键代码如下：
```cpp
virtual void Func(char *File) {
    int fd;
    char temp;
    int num = 0;
    if (-1 == (fd = open(File, O_RDONLY)))  //只读方式打开
    {
        cout << "Can not open: " << File << endl;
        return;
    }
    while (read(fd, &temp, 1))  //每读取一个字符就加1
    {
        num++;
    }
    close(fd);  //关闭文件
    if (0 == num) {
        cout << "Empty file: " << File << endl;
    }
    cout << File << " size is : " << num << endl;  //打印文件大小
}
```
实现插件6：与实现插件3，4类似，只是把调用的函数换成打印文件大小的函数而已。

调用插件部分设计：
设计实现了2个类，```class SearchPlugin```用来实现在目录plugin下搜索插件，```class CPluginController```用来管理插件。两个类如下：
```cpp
class SearchPlugin {
   public:
    SearchPlugin() {}
    ~SearchPlugin() {}
    bool GetPlugin(vector<string> &PluginName);
};

class CPluginController {
   public:
    CPluginController(void);
    virtual ~CPluginController(void);

    bool InitializeController(void);    //初始化
    bool UninitializeController(void);  //释放

    bool ProcessHelp(void);
    bool ProcessRequest(int FunctionID);
    bool IfProcess(char *Function);  //判断插件是否存在
    bool ProcessFunction(char *Function, char *Document);  //执行插件1，2，5
    bool ProcessFunction(char *Function, char *Dir,
                         char *Suffix);  //执行插件3，4，6
   private:
    std::vector<void *> m_vhForPlugin;
    std::vector<IPlugin *> m_vpPlugin;
};
```

主程序部分：因为要求不使用命令行，所以使用一个while (1)来不断接收用户的命令。

执行插件的关键代码：
```cpp
if (input == 'r')  //执行插件1，2，5
{
    CPluginController ptr;
    cout << "输入文件名" << endl;
    char File[MAXSIZE];
    cin >> File;
    cout << "输入执行的插件代号" << endl;
    char Function[MAXSIZE];
    cin >> Function;
    ptr.InitializeController();            //初始化
    if (ptr.IfProcess(Function) == false)  //判断插件是否存在
    {
        cout << "No this plugin!" << endl;
    } else {
        ptr.ProcessFunction(Function, File);  //调用插件功能
    };
    ptr.UninitializeController();  //释放
    if (input == 'e')              //输入'e'时退出
    {
        exit(0);
        break;
    }
}
if (input == 'd')  //执行插件3，4，6
{
    CPluginController ptr;
    cout << "输入目录名" << endl;
    char Dir[MAXSIZE];
    cin >> Dir;
    cout << "输入后缀名" << endl;
    char Suffix[MAXSIZE];
    cin >> Suffix;
    f cout << "输入执行的插件代号" << endl;
    char Function[MAXSIZE];
    cin >> Function;
    ptr.InitializeController();            //初始化
    if (ptr.IfProcess(Function) == false)  //判断插件是否存在
    {
        cout << "No this plugin!" << endl;
    } else {
        ptr.ProcessFunction(Function, Dir, Suffix);  //调用插件功能
    };
    ptr.UninitializeController();  //释放
    if (input == 'e')              //输入'e'时退出
    {
        exit(0);
        break;
    }
}
```




