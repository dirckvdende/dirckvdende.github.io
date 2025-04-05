---
layout: post
title: "JSON Schemas are Awesome!"
date: 2025-04-04 21:50:00 +0200
categories: blog
---

While I was working on my Master's thesis, for the millionth time now, I had to come up with some input format. Of course, I go for the easiest solution and use JSON files as input. With one line of Python code the file contents can be converted to a dictionary, list, etc. However: What happens if a user does not follow the format I carefully came up with? Well, for that you need to write lots code to check there are no extra items, missing items, incorrect types, incorrect list lengths, ... *sigh*. This could be made so much easier right? Well it turns out there is a very nice solution to my problem: JSON schemas.

How I never came across JSON schemas I don't know, but I do know I'll use them *a lot* in future projects! How does it work you ask? We define a JSON format using more JSON. Let's look at a simple example: We want to check some username and password, which are supplied using JSON like so:
```json
{
    "username": "fluffy_cat",
    "password": "hello_world"
}
```
In Python we could parse this using the following code:
```py
import json
data = json.loads(raw_text)
```
Easy enough. But if the user supplies a number as the password field it still loads everything, or worse: The password field could be left out! Now we're relying on the code after load to handle all of these cases properly. This can quickly lead to messy code and bugs.

## How JSON Schemas Work

For our simple JSON format we want to validate that the user supplies a JSON string with the two fields `username` and `password`, both of which are strings. A JSON schema for this would look something like this:
```json
{
    "type": "object",
    "required": ["username", "password"],
    "additionalProperties": false,
    "properties": {
        "username": {"type": "string"},
        "password": {"type": "string"}
    }
}
```
Then in the Python code we would add an extra check using the [jsonschema] library:
```py
import json
import jsonschema
data = json.loads(raw_text)
jsonschema.validate(instance=data, schema=schema_raw_text)
```
If there is something wrong with the input, an exception is thrown. Useful, isn't it? And you can do much more with JSON schemas, such as defining types of list items, optional properties, and more! But my favorite thing about JSON schemas is its support in VSCode, the editor I use most of the time. It has built in support for schemas with autocompletions. You can indicate which JSON schema a file follows by adding a `$schema` property to the root. For example:
```json
{
    "$schema": "schema_file.json",
    "username": "fluffy_cat",
    "password": "hello_world"
}
```
This does give an error though, since before we required that there were no additional properties to the root, and now there is a property `$schema`. To fix this, add an optional property `$shema`. In addition we can also add a `$schema` property to the schema file itself, which indicates the schema standard used. This way we get autocompletions for our schema files as well! The final schema file will look something like this:
```json
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "required": ["username", "password"],
    "additionalProperties": false,
    "properties": {
        "schema": {"type": "string"},
        "username": {"type": "string"},
        "password": {"type": "string"}
    }
}
```
For an overview of everything you can do with JSON schemas, check out [json-schema.org].

[jsonschema]: https://pypi.org/project/jsonschema/
[json-schema.org]: https://json-schema.org/