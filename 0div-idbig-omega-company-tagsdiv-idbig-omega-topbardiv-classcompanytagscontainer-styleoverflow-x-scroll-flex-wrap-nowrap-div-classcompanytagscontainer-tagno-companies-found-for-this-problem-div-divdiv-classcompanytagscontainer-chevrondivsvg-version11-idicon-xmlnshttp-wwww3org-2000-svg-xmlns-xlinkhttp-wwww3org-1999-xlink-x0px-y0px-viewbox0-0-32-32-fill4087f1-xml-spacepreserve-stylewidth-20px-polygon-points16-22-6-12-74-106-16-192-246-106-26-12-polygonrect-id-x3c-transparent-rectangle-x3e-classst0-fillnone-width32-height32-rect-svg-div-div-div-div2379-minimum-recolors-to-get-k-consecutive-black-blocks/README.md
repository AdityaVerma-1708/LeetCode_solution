<h2><a href="https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2379. Minimum Recolors to Get K Consecutive Black Blocks</a></h2><h3>Easy</h3><hr><div><p>You are given a <strong>0-indexed</strong> string <code>blocks</code> of length <code>n</code>, where <code>blocks[i]</code> is either <code>'W'</code> or <code>'B'</code>, representing the color of the <code>i<sup>th</sup></code> block. The characters <code>'W'</code> and <code>'B'</code> denote the colors white and black, respectively.</p>

<p>You are also given an integer <code>k</code>, which is the desired number of <strong>consecutive</strong> black blocks.</p>

<p>In one operation, you can <strong>recolor</strong> a white block such that it becomes a black block.</p>

<p>Return<em> the <strong>minimum</strong> number of operations needed such that there is at least <strong>one</strong> occurrence of </em><code>k</code><em> consecutive black blocks.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> blocks = "WBBWWBBWBW", k = 7
<strong>Output:</strong> 3
<strong>Explanation:</strong>
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> blocks = "WBWBBBW", k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == blocks.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>blocks[i]</code> is either <code>'W'</code> or <code>'B'</code>.</li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>
</div>