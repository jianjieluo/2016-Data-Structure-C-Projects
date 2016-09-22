# Project 1 --- 火车车厢重排调度

`班级：教务3班
姓名：罗剑杰  学号：15331229
姓名：卢健彬  学号：15331225
姓名：卢童杰  学号：15331226
姓名：刘俊君  学号：15331214`

##【题目要求】
给定一个任意的车厢排序次序。重新排列车厢，使其按照从1到n的次序排列。给出调度详细步骤。规定重排调度时车厢只能从入轨到缓冲铁轨，或者从缓冲铁轨到出轨。

##【数据结构与算法】
要求是按从小到大的顺序排列的，而栈是遵循后进先出的原则的。
1. 进栈情况: **栈内元素应按栈顶比栈底小的次序排列**
2. 出栈情况: **判断栈顶元素是否应该出栈**

> 详细实现以及每一步的操作在代码里面已经有了很完备的注释，主要是每一次操作根据实时的情况分情况进行栈的处理

##【测试数据、结果及分析】
输入数据：4  2341，运行结果如图1所示。
```
longj@longj-working-bench:~/DS_projects/Project1-9.8$ ./bin/trainSort
The number of carriages : 4
The order : 2 3 4 1
Begin:
Step:1
Stack 1:2
The correct train :
---------------------------------------------
Step:2
Stack 1:2
Stack 2:3
The correct train :
---------------------------------------------
Step:3
Stack 1:2
Stack 2:3
Stack 3:4
The correct train :
---------------------------------------------
Step:4
Stack 1:2
Stack 2:3
Stack 3:4
The correct train : 1
---------------------------------------------
Step:5
Stack 2:3
Stack 3:4
The correct train : 1 2
---------------------------------------------
Step:6
Stack 3:4
The correct train : 1 2 3
---------------------------------------------
Step:7
The correct train : 1 2 3 4
---------------------------------------------
The total number of the stacks used is: 3
```

输入数据：5  54213，运行结果如图2-1所示。

```
longj@longj-working-bench:~/DS_projects/Project1-9.8$ ./bin/trainSort
The number of carriages : 5
The order : 5 4 2 1 3
Begin:
Step:1
Stack 1:5
The correct train :
---------------------------------------------
Step:2
Stack 1:5 4
The correct train :
---------------------------------------------
Step:3
Stack 1:5 4 2
The correct train :
---------------------------------------------
Step:4
Stack 1:5 4 2
The correct train : 1
---------------------------------------------
Step:5
Stack 1:5 4
The correct train : 1 2
---------------------------------------------
Step:6
Stack 1:5 4
The correct train : 1 2 3
---------------------------------------------
Step:7
Stack 1:5
The correct train : 1 2 3 4
---------------------------------------------
Step:8
The correct train : 1 2 3 4 5
---------------------------------------------
The total number of the stacks used is: 1
```

##【分工】
+ 罗剑杰：代码结构优化与注释，项目规范化，实验报告md文件完善书写
- 卢健彬：完成主体代码。
- 卢童杰：完成实验报告。
- 刘俊君：优化输出，添加抵御非法输入的代码

##【项目总结】
1. 有时没考虑到在空栈情况下非法访问top()，导致segmentation fault的出现，进一步练习对gdb的使用，提高了我们的debug能力（被迫的）。
2. 更深入地了解并掌握栈的使用，尝试运用c++11的新特性，这给我们后面的学习带来很大帮助。
3. 进一步熟悉git的使用，这给我们团队的协作带来很大方便（其实一开始并不方便，因为大家都不熟练，挖了一堆坑= =），并且提高了我们团队合作的意识。
4. 考虑到非法输入等问题， 我们还加入了catch和throw函数，使得我们项目更为健壮。
5. 有可能的话会在以后有空的时候将代码改成可以一次运行，多次排序的情况，具体需求在github上面有todo.md说明，那是后期自娱自乐了：）



---
More Information：
https://github.com/longjj/2016-Data-Structure-C-Projects
