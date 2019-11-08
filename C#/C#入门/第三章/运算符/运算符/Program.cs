using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;         //拥有这行代码的话，可以不需要使用Console.Writeline(),而只需要使用Writeline().
using static System.Convert;         //同上

namespace 运算符
{
    class Program
    {
        static void Main(string[] args)
        {
            double firstnumber, secondnumber;
            string userName;
            WriteLine("Enter your name:");             //Writeline()函数会自动换行.
            userName = ReadLine();
            WriteLine($"Welcome {userName}!");         //$：在输出的话中插入参数.
            WriteLine("Now give me a number:");
            firstnumber = ToDouble(ReadLine());        //ToDouble()类型转换函数，将输入转换为double.
            WriteLine("Now give me another number:");
            secondnumber = ToDouble(ReadLine());
            WriteLine($"The sum of {firstnumber} and {secondnumber} is " + $"{firstnumber+secondnumber}");
            //当要在Writeline()函数中加入表达式时，可以用+链接两个${...},$插入参数.
            WriteLine($"The 减法 of {firstnumber} and {secondnumber} is " + $"{firstnumber-secondnumber}");
            WriteLine($"The 乘法 of {firstnumber} and {secondnumber} is " + $"{firstnumber*secondnumber}");
            WriteLine($"The 除法 of {firstnumber} and {secondnumber} is " + $"{firstnumber/secondnumber}");
            WriteLine($"The 取余 of {firstnumber} and {secondnumber} is " + $"{firstnumber%secondnumber}");
            ReadKey();
        }
    }
}
