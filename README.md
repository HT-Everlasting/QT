# Qt Learning Projects

本仓库收录了一系列基于 **Qt** 框架的示例程序与练习项目，涵盖了 Qt 的基础用法、信号与槽机制、界面设计、资源管理、自定义控件、绘图、以及一个小游戏 **CoinFlip**。  
适合 Qt 初学者或希望快速上手 Qt C++ 开发的同学参考。

---

## 📂 项目结构

qt/
├── 01_qt # 基础窗口 & 翻译文件
├── 02_signals # 信号与槽机制示例
├── 03_qmainwindow # 使用 QMainWindow
├── 04_Qtsource # 资源文件 (qrc) 使用
├── 05_Qttreewidget # QTreeWidget 示例
├── 06_smallwidget # 自定义小控件 & 事件
├── 07_Qpaintdevice # 绘图设备与事件
└── CoinFlip # 翻金币小游戏

---

## 🚀 功能特性

- **01_qt**  
  - 基础窗口程序  
  - 使用 `.ui` 文件进行界面设计  
  - 多语言翻译文件示例（`01_qt_zh_CN.ts`）

- **02_signals**  
  - 演示 Qt 的 **信号与槽**  
  - `teacher` 与 `student` 类的事件交互  

- **03_qmainwindow**  
  - 使用 `QMainWindow` 搭建应用主窗口  
  - 菜单栏、工具栏与状态栏  

- **04_Qtsource**  
  - 使用 Qt 资源文件 `.qrc`  
  - 界面与图片、图标绑定  

- **05_Qttreewidget**  
  - `QTreeWidget` 的使用  
  - 树形控件的创建与层级关系  

- **06_smallwidget**  
  - 自定义 `QWidget` 子类  
  - 鼠标事件与标签交互  
  - 小部件组合与布局  

- **07_Qpaintdevice**  
  - Qt 绘图设备示例  
  - 自定义绘制事件（`paintEvent`）  

- **CoinFlip**  
  - 一个完整的小游戏 —— **翻金币**  
  - 主场景、关卡选择场景、游戏场景  
  - 使用 `QSound`、自定义按钮、动画  

---

## 🛠️ 技术栈

- **语言**: C++  
- **框架**: Qt (Qt Widgets, Qt Core, Qt GUI)  
- **IDE**: Qt Creator / Visual Studio + Qt 插件  

---

## 📦 使用说明

### 环境准备
1. 安装 [Qt](https://www.qt.io/download) (建议 Qt 5.12+ 或 Qt 6)  
2. 安装编译工具链（如 MinGW 或 MSVC）  
3. 使用 **Qt Creator** 打开 `.pro` 工程文件  

### 编译运行
- 打开子目录下的 `.pro` 文件，例如 `02_signals/02_signals.pro`  
- 点击 **运行 (Run)** 即可编译并启动程序  

### 命令行构建
```bash
qmake 02_signals.pro
make
./02_signals
