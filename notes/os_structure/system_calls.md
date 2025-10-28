# System calls

---

### 🌟 **What are System Calls?** 🌟

System calls act as the **bridge** between your program and the Operating System! They allow programs to request services directly from the **kernel** (the heart of the OS). 💖💻

```diagram
┌────────────────────────┐
│     **User Mode**      │
│   ┌───────────────┐    │
│   │**Kernel Mode**│    │  ---> **Privilege Mode** (Superpower Mode 😎)
│   └───────────────┘    │
└────────────────────────┘
```

> 💡 **Key takeaway**: System calls let programs ask the OS to do things like open files, access memory, or communicate with devices! 🚀

---

### 📝 **System Call Example: Copy a File** 📝

Imagine you're copying a file to a new location. Here's how it flows:

1. **Input filename** 📂
2. **Display prompt** on screen 🖥️
3. **Accept user input** 📝
4. **Output filename** 📁
5. **Display another prompt** 🔄
6. **Accept output filename input** 🖊️
7. **Open input file** 🔓
8. If the file doesn’t exist: **abort** ❌
9. **Create output file** 🆕
10. If the output file exists: **abort** 🚫

### 💥 Why This Matters 💥

- System calls are written in **C/C++** and are **critical** for interacting with the OS. Without them, your program wouldn't know how to handle things like file access, memory management, or even communicating with hardware! 🛠️
- They make sure your program can **safely** ask the OS to perform tasks that require more permissions.
