---
layout: project
title: Ladybug-lang
front_image:
  - url: /assets/img/projects/ladybug_300.jpg
  - url: /assets/img/projects/ladybug_600.jpg
    scale: 2
accent_color: "#829c3b"
tags: Language Interpreter
---

Minimalistic programming language with a TypeScript interface. By the default the language has no IO, meaning it's fully self-contained. I built it as a very short-term project.

The project code and further information can be found on GitHub:

{% include center-button.html href="https://github.com/dirckvdende/ladybug-lang" text="GitHub project" icon="link" %}

## Syntax

The syntax is roughly based on JavaScript, but much simpler. Below are some examples.
```js
if (x > 3) {
    y = 6;
    x = 4;
} else if (x == 2) {
    y = 7;
} else {
    y = 8;
}
```
```js
while (x > 3)
    x -= 1;
```
```js
function fib(x) {
    if (x > 2)
        return fib(x - 1) + fib(x - 2);
    return 1;
}
```

## Use in a TypeScript project

The interpreter can be run from TypeScript:
```ts
import { Ladybug } from "./src/ladybug.mjs";
let lb = new Ladybug();
lb.execute("x = 5;");
```
To add interaction with TypeScript code, a handle can be added. The following example demonstrates this with a `print` statement:
```ts
import { Ladybug, ReturnValue, ValueType } from "./src/ladybug.mjs";
let lb = new Ladybug();
lb.handles.add("print", (args: ReturnValue[]): ReturnValue => {
    console.log(args[0].content);
    return new ReturnValue(ValueType.VOID, "");
});
lb.execute("x = 5; print(x);")
```