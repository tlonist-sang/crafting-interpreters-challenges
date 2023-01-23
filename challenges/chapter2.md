1. pick an open source implementation of a language you like. Download the source code and poke around in it. Try to find the code that implements the scanner and parser. Are they handwritten, or generated using tools like Lex and Yacc?(.l or .y files usually imply the latter)
- Let's take a look at a **Clojure** source code for an example.
- To start off, Clojure is a language, and also is a Java Library(compiler) that compiles Clojure codes to byte codes.
### Scanner
- read function from REPL will have the clue. (read-line?)


### Parser
- From Compiler.java file, or 'eval' part of REPL


2. Just-in-time compilation tends to be the fastest way to implement dynamically typed languages, but not all of them use it. what reasons are there to not JIT?
- JIT compiles a code to a machine code during a runtime. It is thus generally more complex to implement, harder to debug, sometimes can require more boost time, and needs extra care to consider all the platforms the code may be run.

3. Most Lisp implementations that compile to C also contain an interpreter that lets them execute Lisp code on the fly as well. Why?
- Because they use REPL?
