# LeftRecursionANDLeftFactoringProgram

Left Factoring is a grammar transformation technique. It consists in "factoring out" prefixes which are common to two or more productions.

For example, going from:

A → α β | α γ

to:

A → α A'

A' → β | γ

Left Recursion is a property a grammar has whenever you can derive from a given variable (non terminal) a rhs that begins with the same variable, in one or more steps.

For example:

A → A α

or

A → B α

B → A γ

There is a grammar transformation technique called Elimination of left recursion, which provides a method to generate, given a left recursive grammar, 
another grammar that is equivalent and is not left recursive.
