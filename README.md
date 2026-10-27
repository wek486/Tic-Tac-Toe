<div align="center">

# Tic-Tac-Toe · 井字棋

用 C++ 与 EasyX 学习鼠标交互、棋盘绘制和轮流落子。

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square) ![EasyX](https://img.shields.io/badge/EasyX-16a34a?style=flat-square) ![3 × 3](https://img.shields.io/badge/3%20%C3%97%203-7c3aed?style=flat-square)

</div>

---

## 项目内容

- 600 × 600 图形窗口，绘制 3 × 3 棋盘。
- 鼠标点击空格落子，`o` 与 `x` 轮流行动。
- 代码包含胜负、平局检查及消息提示逻辑。

## 操作

点击棋盘空格即可落子，已有棋子的格子不接受重复落子。

## 本地运行

环境：Windows、Visual Studio C++ 桌面开发工具、与目标架构匹配的 EasyX。工程使用的工具集以 `.vcxproj` 为准；本机版本不同可在项目属性中重定向。

```sh
git clone --branch master https://github.com/wek486/Tic-Tac-Toe.git
cd Tic-Tac-Toe
```

1. 打开 `小游戏.slnx`，选择相应平台和编译配置。
2. 确认 EasyX 的头文件与库已配置，再生成项目。
3. 此项目直接绘制棋盘，无需额外图片资源。

以上是按仓库代码整理的运行步骤，未在此次文档整理中完成编译验证。

## 当前实现状态

源码保留了初学阶段的问题：地图定义为 `char map[3][3]`，但部分函数参数和循环使用了 15 列，存在编译及越界问题；另外可检查 `releasecapture()` 的拼写和工程字符集设置。当前应作为学习与调试示例阅读，完成修正后再运行。

## 建议阅读顺序

`main.cpp`：初始化棋盘 → 读取鼠标消息 → 尝试落子 → 切换棋子 → 绘制 → 检查结束条件。

---

如果你也在学习这个方向，欢迎通过 Issues 交流思路、反馈问题。遇到不理解的实现，可以结合代码与 AI 提问，先理解，再动手修改。
