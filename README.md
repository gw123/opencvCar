# opencvCar
基于视频自动循迹小车

##BeisheAndroid 是一个手机端的app
##Bishe  是电脑服务端程序
##lanya  是stem32上运行的程序

软件准备：

1.QT5.5  for Android （windows）版。

  下载地址：https://qt-project.org/downloads 

2.Java Platform (JDK) 7u45
  下载地址：
http://www.oracle.com/technetwork/java/javase/downloads/jdk7-downloads-1880260.html
找到jdk-7u45-windows-i586.exe下载。

 下完安装。
   安装会让你选择安装路径，希望使用默认的。安装完成你会发现在安装目录里有个2个文件夹。
注意我的安装目录为默认的c:\program files\java
 接下来设置环境变量：我的电脑-系统属性-高级，中找到“环境变量”点击新建即可。注意变量值都是以分号为间隔的。
我们新建系统变量ClassPath，填入C:\Program Files\Java\jdk1.7.0_45\bin然后点确定。
同样方法再建立一个JAVA_HOME,值为C:\Program Files\Java\jdk1.7.0_45
然后确定。
   再找到Path环境变量，加入qt的安装路径。如果这个变量值中有其他的值，要在我们添
加的路径前加个英文态分号哦！;D:\Qt\Qt5.2.0\5.2.0\mingw48_32\bin。如果没有别的值就不要加了
。我把qt for android版的qt安装在了D盘。

3.adt-bundle-windows-x86-20131030（也就是安卓的JDK）
下载地址http://developer.android.com/sdk/index.html#download
找到下图所示的标志，点击，接着会弹出一个页面，你点击同意后，选择32位的下载即可。
 下载完成后是个压缩包，你需要解压。
我解压到了F盘，自己建立的android文件夹中了。你也可以跟我学，也在f盘建立一个andr
oid文件夹。这样你就可以完全复制我的变量值了。F:\android\adt-bundle-windows-x86-2
0131030\sdk\tools填入PATH环境变量中。主要在路径前加个英文的分号哦。如下图
接着找到SDK Manager。exe运行。打开后，它会自动检查更新，时间不短。

4.android-ndk-r9b-windows-x86
下载地址：http://developer.android.com/tools/sdk/ndk/index.html
 下载解压。我还是在F盘的android文件夹里哦。
新建androidNDKHOST环境变量
值为F:\android\android-ndk-r9b-windows-x86\android-ndk-r9b

5.apache-ant-1.9.2-bin
下载地址http://ant.apache.org/bindownload.cgi

打开android 版 QT
选择浏览进行路径的配置。然后点击启动Android AVD管理器。添加一个虚拟手机即可。接着等待一会会在列表中显示了。
我列表中显示的是名称1.   看看你的列表旁的添加按钮能不能用，如果能用，你直接点添加给个设备名字也行。
然后建立个android的项目。我建立的是QUICK项目建立过程中会让你选一个环镜。
接着就是运行了。点调试按钮。如果环境你选的不对，就会出现运行错误。在模拟器界面中找到你的项目名，图标为小安卓机器人。
点击它运行运行结果。

将程序打开运行即可。
