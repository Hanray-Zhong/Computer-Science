using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace 类型转换
{
    class Program
    {
        static void Main(string[] args)
        {
            short shortResult, shortVal = 4;
            int integerVal = 67;
            long longResult;
            float floatVal = 10.5F;
            double doubleResult, doubleVal = 99.999;
            string stringResult, stringVal = "17";
            bool boolVal = true;
            WriteLine("Variable Conversion Examples\n");
            doubleResult = floatVal * shortVal;                 //此处进行了隐式转换 等价于shortVal*(short)floatVal
                                                                //且返回值为int型
            WriteLine($"Implicit,->double:{floatVal}*{shortVal}->{doubleResult}");
            shortResult = (short)floatVal;
            WriteLine($"Explicit,->short:{floatVal}->{shortResult}");
            stringResult = Convert.ToString(boolVal) + Convert.ToString(doubleVal);
            WriteLine($"Explicit,->string:\"{boolVal}\"+\"{doubleVal}\"->"+$"{stringResult}");
            longResult = integerVal + ToInt64(stringVal);
            WriteLine($"Mixed,->long:{integerVal}+{stringVal}->{longResult}");
            ReadKey();
        }
    }
}
