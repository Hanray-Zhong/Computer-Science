using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace 练习_5_
{
    class Program
    {
        static void Main(string[] args)
        {
            int a, b, c, d;
            WriteLine("Please enter 4 numbers:");
            a = ToInt32(ReadLine());
            b = ToInt32(ReadLine());
            c = ToInt32(ReadLine());
            d = ToInt32(ReadLine());
            WriteLine($"所以{a},{b},{c},{d}的乘积是：" + $"{a * b * c * d}");
            ReadKey();
        }
    }
}
