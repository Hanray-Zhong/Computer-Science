using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 参数数组
{
    class Program
    {
        static int SumVal(params int[] vals)         //运用params来定义一个参数数组
        {
            int sum = 0;
            foreach(int val in vals)
            {
                sum += val;
            }
            return sum;
        }

        static void Main(string[] args)
        {
            int sum = SumVal(1, 2, 3, 4, 5, 6, 7, 8);
            WriteLine($"sum = {sum}");
            ReadKey();
        }
    }
}
