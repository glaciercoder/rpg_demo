# Programming skills

- For a set of variables defined in a class used for similar purpose, we can use `typedef` so that we can change their type easily.

- When loop up for documents, choose official references first(say cppreference) rather than blogs.		

- When using a type, consider the range of it, especially when using `unsigned`

- `cout` may not know how to tackle with some types, say `uint8_t`, the display is undefined. It may even display nothing.

- If you don't want the implicit type conversion in a function parameter initialization, use `explicit`

- Think carefully of **IS A** and **HAS A** problem, and decide to use inheritance or composition.

- **Delegate Method**: Since polymorphism are evoked only by the pointers and references, we can define a delegate class which is the base class, then derived classes from it. To use the object of the derived class, we define another class A which contains the pointer to delegate class. Then all functions from the  derived class are called via this class A rather than the original class. This will unify the interfaces of the derived class.

  






# Basic Knowledge

- Use `<cstdint>` to specify the size.
- `static const` can not only be used as class data member type, it can also be used in class member function. This will reduce the overhead if the member function is called frequently. Especially for variables that are used just by one member function.
- Use `enum class` will give enum members a scope, it's better to use it rather than enum.