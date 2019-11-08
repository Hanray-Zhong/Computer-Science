using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace foreach循环
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] friendnames = { "hanray", "hanray_zh", "hanray_zhong" };
            WriteLine($"Here are {friendnames.Length} of my friend:");       //WriteLine()自动换行
            foreach (string friendname in friendnames)
            {
                WriteLine(friendname);
            }
            ReadKey();
        }
    }
}
