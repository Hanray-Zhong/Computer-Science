using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Essential_CS.Chapter17
{
    class NameComparison : IComparer<Contact>
    {
        public int Compare(Contact x, Contact y) {
            if (Object.ReferenceEquals(x, y)) {
                return 0;
            }
            if (x == null) {
                return 1;
            }
            if (y == null) {
                return -1;
            }
            int result = StringComparer(x.LastName, y.LastName);
            if (result == 0)
                result = StringComparer(x.FirstName, y.FirstName);
            return result;
        }

        private static int StringComparer(string x, string y) {
            if (Object.ReferenceEquals(x, y)) {
                return 0;
            }
            if (x == null) {
                return 1;
            }
            if (y == null) {
                return -1;
            }
            return x.CompareTo(y);
        }
    }
}
