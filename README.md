# Minimake - A minimalist C++ build system
This is a minimalistic and simple to use C++ build system which I've made while learning C++, to suit my own needs. 

✨**FEATURES**
- ⚙️ Compile a project, consisting of multiple code files into a single executable
- 🔎 Automatically detect C++ code files in your working directory
- 📚 Include libraries in your project

Ease of use was the focus of this project, which is why minimake is likely not suitable for any major projects with specific build needs. However, if you're someone who simply wishes to enjoy C++ coding without worrying about build configurations, this is for you.

🎉 Feedback and suggestions will be greatly appreciated! You may contact me via Discord or Email (contact data found on my GitHub profile).

## How to use
```bash
mkdir ./HelloWorld
cd ./HelloWorld
minimake init # Create a new project and your minimake.conf file
minimake auto # OPTIONAL: Automatically detect C++ code files 
minimake build # Compile your project
```

## Installation
Currently, minimake is only officially supported on Linux systems. However, you can likely get it working on MacOS and Windows as well.

**Linux installation:**
```bash
git clone https://github.com/Loravis/MiniMake
./install.sh
```