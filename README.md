# RepoRadar 
command line interface tool to generate git contributions graph, inspired by [this article](https://flaviocopes.com/go-git-contributions/). built with c++ (version 17+, currently configured to c++20) using libgit2. the colour coding only works on terminals that support ANSI escape codes.

### Build
1. clone the repo
2. change the 'pathToDirectory' and 'githubUsername' variables with directories and users you'd like to monitor
3. cd into the build directory
4. run the following:
```
cmake ..
make
./GitCliContributions
```

### Dependencies
* libgit2
* cmake

libgit2 can be installed via homebrew on MacOS
```
brew install libgit2
```

### Demo
![demo](/assets/demo_gif.gif)

