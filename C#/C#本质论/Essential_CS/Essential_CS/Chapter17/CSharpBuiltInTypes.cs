using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Essential_CS.Chapter17
{
    public class CSharpBuiltInTypes: IEnumerable<string>
    {
        public IEnumerator<string> GetEnumerator() {
            yield return "object";
            yield return "byte";
            yield return "uint";
            yield return "ulong";
            yield return "float";
            yield return "char";
            yield return "bool";
            // ......
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() {
            return GetEnumerator();
        }
    }
}
