using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Essential_CS.Chapter15
{
    public class Patent
    {
        public string Title { get; set; }
        public string YearOfPublication { get; set; }
        public string ApplicationNumber { get; set; }
        public long[] InventorIds { get; set; }
        public override string ToString() {
            return $"{Title} ({YearOfPublication})";
        }
    }

    public class Inventor
    {
        public long Id { get; set; }
        public string Name { get; set; }
        public string City { get; set; }
        public string State { get; set; }
        public string Country { get; set; }

        public override string ToString() {
            return $"{Name} ({City}, {State})";
        }
    }

    public static class PatentData {
        public static readonly Inventor[] Inventors = new Inventor[] {
            new Inventor() {
                Name = "a", City = "aa", State = "aaa", Country = "aaaa", Id = 1
            },
            new Inventor() {
                Name = "b", City = "bb", State = "bbb", Country = "bbbb", Id = 2
            },
            new Inventor() {
                Name = "c", City = "cc", State = "ccc", Country = "cccc", Id = 3
            }
        };
        public static readonly Patent[] Patents = new Patent[] {
            new Patent() {
                Title = "x", YearOfPublication = "1784", InventorIds = new long[] {1}
            },
            new Patent() {
                Title = "y", YearOfPublication = "1877", InventorIds = new long[] {1, 2}
            },
            new Patent() {
                Title = "y", YearOfPublication = "1888", InventorIds = new long[] {3}
            }
        };
    }
}
