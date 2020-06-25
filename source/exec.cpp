#include <iostream>
#include "graph.hpp"


int main(int argc, char* argv[])
 {
   /* stuff */
   //creating a directed graph
   Graph g1{true};
   Graph g2{false};

   auto nd1 = g1.add({"A"});
   auto nd2 = g1.add({"B"});
   auto nd3 = g1.add({"C"});
   auto nd4 = g1.add({"D"});
   auto nd5 = g1.add({"E"});
   auto nd6 = g1.add({"F"});

   nd1->connect(7, nd5);
   nd1->connect(5, nd6);
   nd2->connect(1, nd1);
   nd2->connect(3, nd3);
   nd3->connect(9, nd4);
   nd4->connect(3, nd3);
   nd4->connect(2, nd5);
   nd4->connect(1, nd6);
   nd5->connect(2, nd2);
   nd5->connect(4, nd3);
   nd6->connect(2, nd5);

   auto nu1 = g2.add({"A"});
   auto nu2 = g2.add({"B"});
   auto nu3 = g2.add({"C"});
   auto nu4 = g2.add({"D"});
   auto nu5 = g2.add({"E"});
   auto nu6 = g2.add({"F"});

   nu1->connect(7, nu5);
   nu1->connect(5, nu6);
   nu2->connect(1, nu1);
   nu2->connect(3, nu3);
   nu3->connect(9, nu4);
   nu4->connect(3, nu3);
   nu4->connect(2, nu5);
   nu4->connect(1, nu6);
   nu5->connect(2, nu2);
   nu5->connect(4, nu3);
   nu6->connect(2, nu5);

   g1.ptgraph();
   g2.ptgraph();

   bool test = g1.beFo(nd1);
   std::cout << test << "\n";
   g1.ptgraph();

  return 0;
 }
