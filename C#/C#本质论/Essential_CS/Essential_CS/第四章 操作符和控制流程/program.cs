using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Essential_CS.第四章_操作符和控制流程
{
    class Program
    {
        private static void Main()
        {
            // 空合并操作符
            // expression1 ?? expression2
            string fileName_1 = null;
            string fileName_2;

            fileName_2 = fileName_1 ?? "default.txt";
            System.Console.WriteLine(fileName_2);

            // 空条件操作符
            // ?.
            int[] args = new int[2];
            if (args?.Length != 0)
            {
                int a = (int)args?[0];
                int b = (int)args?[1];
            }
        }
    }
}
