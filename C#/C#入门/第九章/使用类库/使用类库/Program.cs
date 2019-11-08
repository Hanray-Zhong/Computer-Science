using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using ClassLibrary1;

namespace 使用类库
{
    class Program
    {
        static void Main(string[] args)
        {
            MyExternalClass myObj = new MyExternalClass();
            WriteLine(myObj.ToString());
            ReadKey();
        }
    }
}
