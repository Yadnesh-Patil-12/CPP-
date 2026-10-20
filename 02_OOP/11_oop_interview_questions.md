# C++ / OOP Interview Questions - Short Answers

1. **4 pillars of OOP?** Encapsulation (data hiding), Abstraction (expose only essentials), Inheritance (reuse, is-a), Polymorphism (one interface, many forms).
2. **Class vs struct?** Same except default access: class private, struct public.
3. **Compile-time vs runtime polymorphism?** Overloading/templates are resolved at compile time; virtual functions are resolved at runtime through the vtable.
4. **What is a vtable/vptr?** Each class with virtual functions has a table of function pointers; each object stores a hidden pointer (vptr) to it.
5. **Why virtual destructor?** Deleting a derived object through a base pointer without it is undefined behavior (derived part not destroyed).
6. **Pure virtual function / abstract class?** `virtual void f() = 0;` makes the class abstract and not instantiable.
7. **Overloading vs overriding vs hiding?** Overloading: same name, different params in the same scope. Overriding: derived redefines a virtual function with the same signature. Hiding: derived non-virtual function with the same name hides the base one.
8. **Shallow vs deep copy?** Shallow copies pointer values; deep copies the pointed-to data. Write a copy constructor for classes owning raw memory.
9. **Rule of 3/5/0?** If you define destructor, copy ctor or copy assignment, define all three (add move ctor/assign for 5). Prefer Rule of 0 using smart pointers/containers.
10. **Constructor order?** Base first, then members in declaration order, then derived. Destructors run in reverse.
11. **Can constructors be virtual? Can destructors?** Constructors no. Destructors yes (and should be in polymorphic bases).
12. **What is the diamond problem?** Two paths to the same base cause ambiguity; solved with virtual inheritance.
13. **static member / static function?** Shared across all objects; static functions have no `this`.
14. **const member function?** Promises not to modify the object; callable on const objects.
15. **What is `this`?** Pointer to the current object inside non-static member functions.
16. **friend function?** Non-member with access to private members; not inherited, not mutual.
17. **Copy ctor vs assignment operator?** Copy ctor creates a new object; assignment replaces an existing one (needs self-assignment check).
18. **`explicit` keyword?** Stops implicit conversions through single-argument constructors.
19. **Stack vs heap?** Stack: automatic, fast, scoped. Heap: manual (`new/delete`) or via smart pointers, lives until freed.
20. **unique_ptr vs shared_ptr vs weak_ptr?** Exclusive ownership / reference-counted shared ownership / non-owning observer that breaks cycles.
21. **Memory leak / dangling pointer?** Leak: allocated memory never freed. Dangling: pointer to memory that has been freed.
22. **Move semantics?** Transfers resources from a temporary (rvalue) instead of copying; `std::move` casts to an rvalue.
23. **Abstraction vs encapsulation?** Abstraction hides complexity at design level (interfaces); encapsulation hides data at implementation level (private + accessors).
24. **Overloading operators that cannot be overloaded?** `::`, `.`, `.*`, `?:`, `sizeof`.
25. **Template vs macro?** Templates are type-safe and checked by the compiler; macros are plain text replacement.
