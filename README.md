# Programming assignment: Implementing KMP algorithm

In this assignment you are asked to implement the Knuth-Morris-Pratt algorithm for pattern matching.

<strong>The input</strong> is two arrays of characters: text and pattern, with their corresponding lengths N and M.

<strong>The output</strong> is the <em>number</em> of occurrences of a given pattern in the text.

For the full grade, perform the following 4 steps:
<ul>
<li>First of all, implement a naive pattern matching algorithm which runs in time O(NM).</li>

<li>Next, implement the KMP algorithm discussed in class which runs in time O(N). The code for creating an overlap function for a pattern is provided.</li>

<li>Test your KMP implementation for correctness using a short test version. Then run the stress test to make sure you handled all the edge cases and off-by-one errors.</li>

<li>Finally, implement a performance test, which would output the total running time of both algorithms for different input sizes. Range N from 10,000 to 1,000,000, and keep the pattern length M=400. Plot performance results and submit with your work.</li>
</ul>


