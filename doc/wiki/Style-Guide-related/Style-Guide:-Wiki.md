<!-- NOTE: The code section (<pre> or ```) can not be indented in <table> -->

Click the :arrow_forward: to see the example of the style.

> [!IMPORTANT]
> If any of the styles reduces the readability of the code, please do ignore the style.

# Wiki Styles

## Links
<details>
<summary>One space around <code>|</code></summary>
<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=markdown>
[[internal link | internal-file#location]]
</pre>
   </td>
   <td>
<pre lang=markdown>
[[internal link|internal-file#location]]
</pre>
   </td>
</tr>

</table>
</details>

<details>
<summary>No space in square braket</summary>
<table>
<tr>
<td align="center" width="1000"> Good style </td>
<td align="center" width="1000"> Bad style  </td>
</tr>

<tr>
   <td>
<pre lang=markdown>
[[internal link | internal-file#location]]
</pre>
   </td>
   <td>
<pre lang=markdown>
[[ internal link | internal-file#location ]]
</pre>
   </td>
</tr>

</table>
</details>

## Code block
* Code block <code>```</code> is used for commands, code, or anything that needs to be copied. Otherwise, please use `<pre>` to wrap the output.

## Alerts
* Please use the [alerts](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#alerts) to highlight important content.

## Files
* Image files should be placed under `doc/wiki/image`.
* Related files should be placed under the same directory, e.g. `Runtime-Paramters:*.md` are under `Runtime-Parameters-related`.
