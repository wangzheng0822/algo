与 Java 、PHP 等语言不同，在 JavaScript 中，数组其实是一种特殊的对象。
#### 数组的创建与读写
以下两种方式都可创建数组：
```
// 字面量方式,常用
var num = [1,5,6,10];
print(num.length);   // 4

// 构造函数方式
var num = new Array(1,5,6,10);
print(num.length);    // 4
```
值得注意的是，JavaScript 中的数组数据可以是不同类型，它的语法相对宽松，例如可以指定不同类型数据`var example = [1,"Mike",true,null];`另外，可以通过`Array.isArray()`来判断一个对象是否是数组，例如：
```
var num = [1,5,6,10];
print(Array.isArray(num));        // true
```
如何读写数组呢？可以使用循环。
```
var num = [1,5,6,10];
for (var i = 0; i < num.length; i++) {
  console.log(num[i]+" ");
}
```
#### 数组的深复制与浅复制
当我们把数组赋给另外一个数组，然后改变其中一个数组的值，另一数组也会随之改变，这就是数组的浅复制。而深复制指的就是不改变原来的数组而去创建一个新的数组，这种情况是经常使用的，为了不破坏原数组。下面的代码展示了这两种复制
```
// 浅复制
var num = [1,2,3,4,5];
var newNum = num;
num[0] = 10;
console.log(newNum[0]);  // 10

// 深复制
function copy (arr1,arr2) {
  for(var i=0;i<arr1.length;i++){
    arr2[i] = arr1[i];
  }
}
var num = [1,5,6,7,9];
var newNum = [];
copy(num,newNum);
num[0] = 10;
console.log(newNum[0]);    // 仍然为 1
```
#### 存取函数
JavaScript 提供了一组用来访问数组元素的函数，叫存取函数。最常用的存取函数就是 indexOf() 函数，该函数返回指定查找的值在目标值中是否存在，如果存在，返回该值在数组中的索引，不存在则返回 -1。
```
var word = ["A","B","C","D"];
var result = word.indexOf("A");
console.log(result);    // 0
var test = word.indexOf("F");
console.log(test);   // -1
```
除此之外，还有 join 和 toString 函数，concat 和 splice 函数。前两个函数可以将数组转化为字符串，后面两个函数可以通过已有的数组创建新数组，其中 concat 方法通过合并多个数组来形成新数组，而 splice 方法是截取一个数组的子集作为一个新数组。它们的使用示例如下
```
var arr = ["Mike","John","Hexo"];
console.log(arr.join());   // Mike,John,Hexo
console.log(arr.toString());   // Mike,John,Hexo

var arr1 = [1,10,"Mike"];
var arr2 = [8,7,6];
var cat = arr1.concat(arr2);
console.log(cat);    // [1, 10, "Mike", 8, 7, 6]
var num = [1,2,3,4,5,6,7];
var a = num.splice(3,2);     // 3 表示索引，2 表示删除 2 个
console.log(num);      // [1, 2, 3, 6, 7]    
```
#### 可变函数
不去引用数组中的某个元素，就能改变数组内容，这种函数称它为可变函数。
###### push() 和 unshift()、pop() 和 shift()
push() 方法可以在数组末尾添加元素，而 unshift() 方法可以在数组开头添加元素；相对应的，pop 可以删除数组末尾的元素，而 shift 删除数组的第一个元素。
```
var nums = [9,58,15,16,23];
nums.push(111);
console.log(nums);   // 9, 58, 15, 16, 23, 111
nums.unshift(1);
console.log(nums);   // 1, 9, 58, 15, 16, 23, 111
nums.pop();
console.log(nums);   // 1, 9, 58, 15, 16, 23
nums.shift();
console.log(nums);   // 9, 58, 15, 16, 23
```
###### splice()、sort()、reverse()
前面提到的 splice 不仅可以用来删除元素，还可以添加元素进数组。用 sort 可以为数组排序，reverse 将数组内的元素翻转。
```
var num = [98,99,100,101];
num.splice(1,0,89);     // 1 表示索引，0 表示不删除元素，89 表示将 89 这个元素添加进数组
console.log(num);    // 98, 89, 99, 100, 101
num.reverse();
console.log(num);    //  101, 100, 99, 89, 98
```
关于 sort 方法非常有意思，它只能对那些字符串类型的元素排列得比较准确，但如果是数字，结果就不那么令人满意了。看看例子.
```
var str = ["hello","client","zero"];
str.sort();
console.log(str);     // ["client", "hello", "zero"]  按照字母 a-z 排列准确
var nums = [1,200,51,66,88];
nums.sort();
console.log(nums);   // [1, 200, 51, 66, 88]  有趣的事情来了，因为 200 的 2 比 51 的 5 先，所以 200 排在 51 前头
```
那如何解决这种排序的错误呢？方法就是在调用 sort() 的时候传入一个函数，该函数可以比较出大小。
```
function compare(num1,num2){
  return num1 - num2;
}
var nums = [3,1,2,100,4,200];
nums.sort(compare);
console.log(nums);    // 1, 2, 3, 4, 100, 200
```
可以看到，已经排序正确了，compare 函数就是利用了两数相减，如果结果为正，那么被减数大于减数，如果结果为 0，则两数相等，而如果结果为负，说明被减数小于减数。
#### 迭代器方法
迭代函数通过对数组中的元素逐个应用，来操作返回相应的值。
###### 不返回新数组的 forEach() 、every()、some()、reduce()
```
// 用 forEach 开方
function square(num) {
    console.log(num,num*num);
}
var num = [1,2,3,4,5];
num.forEach(square);
console.log(num);
/*  1 1
    2 4
    3 9
    4 16
    5 25
*/
```
```
/*
every() 返回值为布尔类型，对于应用的所有元素，该函数返回 true，则该方法返回 true
*/
function isEven(num){
  return num % 2 == 0;
}
var num = [2,4,6,8,10];
var even = num.every(isEven);
if(even){
  console.log("所有的数字都是偶数");
}else{
  console.log("不是所有的数字都是偶数");
}
```
```
/*
some() 与 every() 的不同就是只要有一个元素使改函数返回 true ，那么该方法就返回 true
*/
function isEven(num){
  return num % 2 == 0;
}
var num = [1,2,3,4,5,6,7,8];
var someEven = num.some(isEven);
if(someEven){
  console.log("有些数字是偶数");
}else{
  console.log("没有数字是偶数");
}
```
```
/*
reduce() 有两个功能，一是可以对数组元素进行求和，二是将数组元素连接成字符串。
*/
fucntion add(num1,num2){
  return num1 + num2;
}
var num = [1,2,3,4];
var sum = num.reduce(add);
console.log(sum);    // 10

function concat(str,i) {
  return str + i;
}
var words = ["I am ","a ","coder "];
var re = words.reduce(concat);
console.log(re);     // I am a coder
```
###### 返回新数组的 map() 和 filter()
map 的作用与 forEach 是一样的，区别就是 map 函数返回的是一个新数组。
```
function addFive(grade){
  return grade += 5;
}
var grade = [77,82,88,95,90];
var result = grade.map(addFive);
console.log(result);     // 82, 87, 93, 100, 95
```
而 filter 和 every 相似，区别在于当所有的元素使改函数为 true 时，它并不返回布尔类型，而是返回一个新数组。下面这个例子十分有趣，它随机产生10个 0 到 100 的数字作为分数，然后把大于 60 的及格分数筛选出来。
```
function passing(num){
  return num >= 60;
}
var grades = [];
for(var i = 0;i < 11;i++){
  grade[i] = Math.floor(Math.random() * 101);
}
var pass = grades.filter(passing);
console.log("随机产生的 10 个同学的分数为：");
console.log(grades)；
console.log("及格的分数有：");
console.log(pass)；
```
上述代码的输出结果为
> 随机产生的 10 个同学的分数为：
21, 4, 89, 45, 5, 51, 71, 7, 46, 53, 47
及格的分数有：
89, 71
#### 二维数组
JavaScript 可以通过在数组里在嵌套一个数组来形成二维数组。
```
var grades = [
  [88,86,82],
  [91,82,83],
  [77,72,79],
  [86,80,82]
];
console.log(grades[1][2]);    // 83
```
#### 处理二维数组
对于二维数组的处理可以分为两种，一种按列访问，一种是按行访问。
按列访问，外层循环对应行，内层循环对应列。例如，上述的数组，每一行对应一个学生三门科目的成绩记录，可以通过相加所有成绩，然后除以科目数来得到该生的平均成绩。
```
var grades = [
  [88,86,82],
  [91,82,83],
  [77,72,79],
  [86,80,82]
];
var total = 0;
var average = 0.0;
for(var row = 0;row<grades.length;++row){
  for(var col = 0;col<grades[row].length;++col){
    total += grades[row][col];
  }
  average = total/grades[row].length;
  console.log("student "+parseInt(row+1)+" average: "+average.toFixed(2));   // toFixed 表示按照 2 位来保留小数
  total = 0;
  average = 0.0;
}
```
上述代码的输出结果为
> student 1 average: 85.33
student 2 average: 85.33
student 3 average: 76.00
student 4 average: 82.67


对于按行访问，则外层循环对应列，内层循环对应行，例如还是上述数组，现在的数组表示一个学生三场考试四门科目的各科分数，我们来求每场考试的平均成绩
```
var grades = [
  [88,86,82],
  [91,82,83],
  [77,72,79],
  [86,80,82]
];
var total = 0;
var average = 0.0;
//这里假设每场考试的科目都一样，所以可以通过grades[0].length来获取考试数量
for(var col = 0;col <grades[0].length;++col ){
  for(var row= 0;row<grades.length;++row){
    total += grades[row][col];
  }
  average = total/grades.length;
  console.log("exam "+parseInt(col +1)+" average: "+average.toFixed(2));
  total = 0;
  average = 0.0;
}
```
输出结果为：
> exam 1 average: 85.50
exam 2 average: 80.00
exam 3 average: 81.50

其实只要调整 for 循环的顺序就可以控制是按行还是按列来输出，此外，JavaScript 还可以处理一些参差不齐的数组，比如一个二维数组中的数组，有的是两个元素，有的是四个元素，并不是都相同，在这种情况下，JavaScript 依然可以处理运行而不报错，这是因为不管多或少，都可以通过 length 属性来计算。
#### 对象数组
如果你有阅读到这里，你应该可以发现上面的所有例子里数据类型都是基本数据类型，不是数字就是字符串。对象数组，顾名思义，就是数组里面的元素可以是对象，这个与 java 的语法很相似，基本上所有的编程语言都是相通的。看看下面这个例子：
```
function point(x,y){
  this.x = x;
  this.y = y;
}
function show(arr){
  for(var i=0;i<arr.length;i++){
    console.log(arr[i].x + ", "+arr[i].y);
  }
}
var p1 = new Point(1,2);
var p2 = new Point(2,4);
var p3 = new Point(8,1);
var p4 = new Point(2,9);
var point = [p1,p2,p3,p4];
for(var i=0;i<point.lengh;i++){
  console.log("Point "+parseInt(i+1)+": "+point[i].x+", "+point[i].y);
}
```
上述程序的输出结果为：
> Point 1: 1, 2
Point 2: 2, 4
Point 3: 8, 1
Point 4: 2, 9

也可以用之前的 push() 等操作方法来操作对象数组
```
var p5 = new Point(11,13);
point.push(p5);
console.log("添加了 p5 后：");
show(point);     
point.shift();
console.log("删除第一个元素后：")
show(point);
```
输出结果为：
> 添加了 p5 后：
1,2
2,4
8,1
2,9
11,13
删除第一个元素后：
2,4
8,1
2,9
11,13
