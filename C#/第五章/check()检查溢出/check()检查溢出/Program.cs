using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace check__检查溢出
{
    class Program
    {
        static void Main(string[] args)
        {
            byte destinationvar;
            short sourcevar = 281;
            destinationvar = unchecked((byte)sourcevar);                   //将显示错误，程序崩溃
            WriteLine($"destinationvar={destinationvar}");
            WriteLine($"sourcevar={sourcevar}");
            ReadKey();
        }
    }
}
