using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace 布尔运算
{
    class Program
    {
        static void Main(string[] args)
        {
            int myint;
            WriteLine("Enter a integer:");
            myint = ToInt32(ReadLine());
            bool isLessThan10 = myint < 10;
            bool isBetween0and5 = (myint >= 0) && (myint <= 5);    //bool变量即true（非0） 或 false（0）.
            WriteLine($"integer is less than 10? {isLessThan10}");
            WriteLine($"integer is between 0 and 5? {isBetween0and5}");
            WriteLine($"one of the above is true? " + $"{isLessThan10 | isBetween0and5}");
            ReadKey();
        }
    }
}