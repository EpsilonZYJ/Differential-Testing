# Differential-Testing

## How to use?

在1.cpp中编写暴力法求解代码，在datamaker.cpp中编写/修改随机数数据生成代码，在work.cpp中编写正常方法所得代码(注意将输入输出重定向)，然后依次编译datamaker.cpp,1.cpp,main.cpp,work.cpp,运行work.exe即可。

运行work.exe时，若两文件产生的结果不同，则会停止运行并显示两者的结果，测试集通过打开data.txt查看即可。

* 注：在此仓库中的1.cpp,main.cpp属于测试代码，无任何意义 *
