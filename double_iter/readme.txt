readme of double_list_iter

I implemented the double list iterator referring to textbook and www.cplusplus.com.

In Iter body is almost same with text book (Code Fragment 6.7) but return value of operator* is int (data1).

I used only one double list in double_receiver_iter.cpp to save input data.
To use stl find() function, I had to inherit std::iterator as bidirectional_iterator.

I find how to inherit iterator to custom iterator at http://www.cplusplus.com/reference/iterator/iterator/