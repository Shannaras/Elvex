Elvex
=====

**Elvex** is a **Natural Text Generator**

It is written by Lionel Clément at Bordeaux University - France and released by LaBRI under GNU GPL License.

The system is using handwritten *lexicon* and *grammar* as parameters, and a *concept* as an input. Finally, it outputs a text in Natural Language that represents exactly the "concept". The "concept" may be the meaning, but also elements of speech like language level, illocutionary acts, enonciative properties, etc. 

programming language used
-------

C++

License
-------

**Elvex** is released under GNU GPL License V3.

In other words

- The source code must be made available when the software is distributed
- A copy of the license and the copyright manual must be included with the software
- Modifications must be released under the same license when the software is distributed. A similar or a related license must be used
- Changes made to the code must be documented

The license shall cover **Elvex** software and the included data except LeFFF which is under another license.

The language of **Elvex** is not under licence (it belongs to the public domain), so the data you will write (new grammars, new lexicons) are not part of **Elvex**, it is under another license.

What you can't do with Elvex
-----------------------------

**Elvex** can write a text that sounds natural, but does not really understand what it is saying.

What you can do with Elvex
-----------------------------

Write automatically and quickly texts in a correct form of Natural Language, given a meaning and elements
of speech. Rest assured that **Elvex** avoids any misunderstanding.

Note that unlike other systems, the concepts that are expressed may not depend on prior lexical choices.

Theoretical aspects
-----------------

**Elvex** is freely inspired by some syntactic formalisms such as: 

-Lexique-Grammaire (M. Gross 1960)
-Functional Grammar (M. Kay 1979)
-Lexical-Functional Grammar (J. Bresnan and D. Kaplan 1982) 
-Systemic Functional Grammar (M. Halliday 1994).

It's working with handwritten lexicons and grammars that are similar to the linguistic descriptions of the syntactic phenomenon but not with learning data.
I don’t explain the algorithms here. It’s efficient and monotonic (each rule adds something and never removes the effect of another rule).

Practically speaking: to build Text Generator with Elvex for an application (Chatbot, Letter-writer, etc)
--------------------

Every time you use a word it has to be fully described in the lexicon, depending on a specific domain. It would be a long and costly process to write all the simple words, compounds and idiomatic phrases (several months for one person in a restricted domain).

The grammar is more complex, but shorter to write (several weeks). In order to help grammar-writers, I am presently writing a grammar design-pattern.

One of the most difficult stuff already done with Elvex
-----------------------------------------------

- Adjective order in English (big yellow squared stuff, not squared yellow big stuff)
- Anaphora resolution process between sentences with pronouns, synonyms and hypernyms
- Complex idiomatic phrases (not always contiguous)
- Past participle aggrement in French with transitive verbs
- Lexical functions (based on Mel'čuk theory)
In progress:
- Coordinations with Right-Node Raising and Gapping

Sample: Causal clauses in a little French Grammar first
-----------------------------------------------

Causal clauses with tense aggrement.

In French, the basis of verbal tense and the conclusion of a causal clause depend on the aspect, the tense and even on the differences in language registers of a sentence

- present: 
if present => future
- present or future in slang language:
conditional without "if" => conditional
- past:
if past => past conditional
- past in slang language:
past conditional without "if" => past conditional
- future:
 Imperfect => conditional

// present
### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]]]
S'il pleut, tu prendras un parapluie.

// present or future & slang language
### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]], language_register:slang]
Il flotterait, tu prendrais un pépin.

// continuous present
### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]], tense:present, aspect:continuous]
S'il est en train de pleuvoir, tu prendras un parapluie.

### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, illocutionary:ask, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]]]
S'il pleut, est-ce que tu prendras un parapluie ?

//past
### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]], tense:past]
S'il avait plu, tu aurais pris un parapluie.

//past & slang language
### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]], tense:past, language_register:slang]
Il aurait plu, tu aurais pris un parapluie.

### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]], tense:past, aspect:continuous]
S'il était en train de pleuvoir, tu aurais pris un parapluie.

//future
### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]], tense:future]
S'il pleuvait, tu prendrais un parapluie.

### text [PRED:cause, i:[PRED:to_rain], ii:[PRED:to_take, i:[PRED:_you], ii:[PRED:umbrella, def:no, number:sg]], tense:future, aspect:continuous]
S'il était en train de pleuvoir, tu prendrais un parapluie.

