<!-- NOTE: The code section (<pre> or ```) can not be indented in <table> -->

Click the :arrow_forward: to see the example of the style.

> [!IMPORTANT]
> If any of the styles reduces the readability of the code, please do ignore the style.

# `C` Style

## General
* The indent is 3 spaces
* 🎯 If the line only has comment, the comment always starts from the beginning
* 🎯 `#` of the preprocessor always starts at the beginning of the line

## Naming
* Global variables are named in all uppercase, e.g. `GAMMA`.
* Variables defined in preprocessor or `Makefile` are named in all uppercase, e.g. `MHD`.

## `for`
<details>
<summary>One space after <code>for</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
   <td>
<pre lang=c++>
for(int i=0; i<10; i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space after <code>;</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
   <td>
<pre lang=c++>
for (int i=0;i<10;i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>No spaces in parenthesis</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
   <td>
<pre lang=c++>
for ( int i=0; i<10; i++ )
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>No spaces in condition</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
   <td>
<pre lang=c++>
for (int i = 0; i < 10; i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary><code>{</code> should be at the next line and have the same indent as <code>for</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++) {
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Add the for loop comment behind <code>}</code> with one space-separated</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
   ... your code here ...
} // for (int i=0; i<10; i++)
</pre>
   </td>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
   ... your code here ...
}// for (int i=0; i<10; i++)
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Align multiple loops for readability</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
for (int i=0; i<2;   i++)
for (int j=0; j<10;  j++)
for (int k=0; k<100; k++)
{
   ... your code here ...
} // for (i, j, k)
</pre>
   </td>
   <td>
<pre lang=c++>
for (int i=0; i<2; i++)
for (int j=0; j<10; j++)
for (int k=0; k<100; k++)
{
   ... your code here ...
} // for (i, j, k)
</pre>
   </td>
</tr>

</table>
</details>

## `while`
<details>
<summary>One space after <code>while</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
   <td>
<pre lang=c++>
while( step < 100  ||  time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space in parenthesis</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
   <td>
<pre lang=c++>
while (step < 100  ||  time < 1.0)
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space in condition</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
   <td>
<pre lang=c++>
while ( step<100  ||  time<1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Use two spaces to separate <code>||</code> and <code>&&</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
   <td>
<pre lang=c++>
while ( step < 100 || time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary><code>{</code> should be at the next line and have the same indent as <code>while</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 ) {
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Add the while loop comment behind <code>}</code> with one space-separated</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 )
{
   ... your code here ...
}// while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Align multiple loops/conditions for readability</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
while ( step < 100  ||  time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||  time < 1.0 )
</pre>
   </td>
   <td>
<pre lang=c++>
while ( step < 100  ||
        time < 1.0 )
{
   ... your code here ...
} // while ( step < 100  ||
//           time < 1.0 )
</pre>
   </td>
</tr>

</table>
</details>

## `if`
<details>
<summary>One space after <code>if</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
   <td>
<pre lang=c++>
if( A == B  ||  B < C )
{
   ... your code here ...
} else if( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space in parenthesis</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
   <td>
<pre lang=c++>
if (A == B  ||  B < C)
{
   ... your code here ...
} else if (D != E)
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space in condition</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
   <td>
<pre lang=c++>
if ( A==B  ||  B < C )
{
   ... your code here ...
} else if ( D!=E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Use two spaces to separate <code>||</code> and <code>&&</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
   <td>
<pre lang=c++>
if ( A == B || B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary><code>{</code> should be at the next line and have the same indent as <code>if</code> and <code>else</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C ) {
   ... your code here ...
} else if ( D != E ) {
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Add the if comment behind <code>}</code> with one space-separated</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
}// if ( A == B  ||  B < C ) ... else if ... else
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Short if (three spaces separated and aligned), add indent if next line</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )  ... short code ...
else if ( D != E )        ... short code ...
else                      ... short code ...
</pre>
   </td>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )  ... short code ...
else if ( D != E )   ... short code ...
else   ... short code ...
</pre>
   </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
   ... short code ...
</pre>
   </td>
   <td>
<pre lang=c++>
if ( A == B  ||  B < C )
... short code ...
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One line if</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
( A == B  ||  B < C ) ? true : false;
</pre>
   </td>
   <td>
<pre lang=c++>
( A == B  ||  B < C ) ? true  :  false;
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Align multiple conditions for readability</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
if ( A == B  ||
     B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||
//        B < C ) ... else if ... else
</pre>
   </td>
   <td>
<pre lang=c++>
if ( A == B  ||
   B < C )
{
   ... your code here ...
} else if ( D != E )
{
   ... your code here ...
} else
{
   ... your code here ...
} // if ( A == B  ||
//        B < C ) ... else if ... else
</pre>
   </td>
</tr>

</table>
</details>

## `switch`
<details>
<summary>One space after <code>switch</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
switch ( d )
{
   case 1: ... your code ... break;
   case 2: ... your code ... break;
   case 3: ... your code ... break;
} // switch ( d )
</pre>
   </td>
   <td>
<pre lang=c++>
switch( d )
{
   case 1: ... your code ... break;
   case 2: ... your code ... break;
   case 3: ... your code ... break;
} // switch ( d )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space in parenthesis</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
switch ( d )
{
   case 1: ... your code ... break;
   case 2: ... your code ... break;
   case 3: ... your code ... break;
} // switch ( d )
</pre>
   </td>
   <td>
<pre lang=c++>
switch (d)
{
   case 1: ... your code ... break;
   case 2: ... your code ... break;
   case 3: ... your code ... break;
} // switch ( d )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary><code>{</code> is at next line and have the same indent as <code>switch</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
switch ( d )
{
   case 1: ... your code ... break;
   case 2: ... your code ... break;
   case 3: ... your code ... break;
} // switch ( d )
</pre>
   </td>
   <td>
<pre lang=c++>
switch ( d ) {
   case 1: ... your code ... break;
   case 2: ... your code ... break;
   case 3: ... your code ... break;
} // switch ( d )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>If the code in case is too long, <code>break;</code> should be indented correctly</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
switch ( d )
{
   case 1: ... your code ...
           break;
   case 2: ... your code ...
           break;
   case 3: ... your code ...
           break;
} // switch ( d )
</pre>
   </td>
   <td>
<pre lang=c++>
switch ( d )
{
   case 1: ... your code ...
      break;
   case 2: ... your code ...
      break;
   case 3: ... your code ...
      break;
} // switch ( d )
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space before the trailing comment</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
switch ( d )
{
   case 1: ... your code ... break;
   case 2: ... your code ... break;
   case 3: ... your code ... break;
} // switch ( d )
</pre>
   </td>
   <td>
<pre lang=c++>
switch ( d )
{
   case 1: ... your code ... break;
   case 2: ... your code ... break;
   case 3: ... your code ... break;
}// switch ( d )
</pre>
   </td>
</tr>

</table>
</details>

## Preprocessors
<details>
<summary>Align <code>\</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
#define func( x, y )     \
{                        \
   return ( (x) + (y) ); \
}
</pre>
   </td>
   <td>
<pre lang=c++>
#define func( x, y ) \
{ \
   return ( (x) + (y) ); \
}
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space before <code>\</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
#define func( x, y )     \
{                        \
   return ( (x) + (y) ); \
}
</pre>
   </td>
   <td>
<pre lang=c++>
#define func( x, y )    \
{                       \
   return ( (x) + (y) );\
}
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Match the current indent</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
#  ifdef MHD
   ... your code ...
#  endif
} // for (int i=0; i<10; i++)
</pre>
   </td>
   <td>
<pre lang=c++>
for (int i=0; i<10; i++)
{
#ifdef MHD
   ... your code ...
#endif
} // for (int i=0; i<10; i++)
</pre>
   </td>
</tr>

</table>
</details>


## Functions
<details>
<summary>No space between the function name and <code>(</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
void function_name( int a, int b )
{
   ... your code ...
} // FUNCTION : function_name
</pre>
   </td>
   <td>
<pre lang=c++>
void function_name ( int a, int b )
{
   ... your code ...
} // FUNCTION : function_name
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space in parenthesis</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
void function_name( int a, int b )
{
   ... your code ...
} // FUNCTION : function_name
</pre>
   </td>
   <td>
<pre lang=c++>
void function_name(int a, int b)
{
   ... your code ...
} // FUNCTION : function_name
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Add description before the function</summary>

<pre lang=c++>
//-------------------------------------------------------------------------------------------------------
// Function    :  function_name
// Description :  Description of the function
//
// Note        :  1. Some notes
//
// Parameter   :  a : argument a
//                b : argument b
//
// Return      : none
//-------------------------------------------------------------------------------------------------------
void function_name( int a, int b )
{
   ... your code ...
} // FUNCTION : function_name
</pre>
</details>

<details>
<summary>Add function name after <code>}</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
void function_name( int a, int b )
{
   ... your code ...
} // FUNCTION : function_name
</pre>
   </td>
   <td>
<pre lang=c++>
void function_name ( int a, int b )
{
   ... your code ...
}
</pre>
   </td>
</tr>

</table>
</details>

## Comments
<details>
<summary>Trailing comment should be separated by one space or be aligned</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
int c = 1; // comment
</pre>
   </td>
   <td>
<pre lang=c++>
int c = 1;// comment
</pre>
   </td>
</tr>

<tr>
   <td>
<pre lang=c++>
int    c = 1;   // comment
double d = 0.0; // comment
</pre>
   </td>
   <td>
<pre lang=c++>
int    c = 1; // comment
double d = 0.0; // comment
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>One space after <code>//</code></summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
int c = 1; // comment
</pre>
   </td>
   <td>
<pre lang=c++>
int c = 1;// comment
</pre>
   </td>
</tr>

<tr>
   <td>
<pre lang=c++>
int    c = 1;   //comment
double d = 0.0; //comment
</pre>
   </td>
   <td>
<pre lang=c++>
int    c = 1;   //comment
double d = 0.0; //comment
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>Match the current indent</summary>

<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=c++>
void function_name( int a, int b )
{
   ... your code ...
      ... your code ...
//    comment
      ... your code ...
   ... your code ...
} // FUNCTION : function_name
</pre>
   </td>
   <td>
<pre lang=c++>
void function_name( int a, int b )
{
   ... your code ...
      ... your code ...
// comment
      ... your code ...
   ... your code ...
} // FUNCTION : function_name
</pre>
   </td>
</tr>

</table>
</details>

## Variables
<details>
<summary>Pointer</summary>
</details>

<details>
<summary>Array</summary>
</details>

<details>
<summary>Casting</summary>
</details>

<details>
<summary>Other?</summary>
</details>
