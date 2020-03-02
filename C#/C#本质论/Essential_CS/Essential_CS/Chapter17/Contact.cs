using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Essential_CS.Chapter17
{
    class Contact
    {
        public string FirstName { get; private set; }
        public string LastName { get; private set; }
        public Contact(string firstName, string lastName) {
            this.FirstName = firstName;
            this.LastName = lastName;
        }
    }
}
