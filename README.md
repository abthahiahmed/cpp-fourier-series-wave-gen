# C++ Fourier Series Wave Generation.

Hey, I am Abthahi Ahmed Rifat. I have created this code according to fourier series on <a href="https://en.wikipedia.org/wiki/Fourier_series#:~:text=A%20Fourier%20series%20(%2F%CB%88f,be%20determined%20using%20harmonic%20analysis.">Wikipedia Link</a>

This will actually create different kind of wave by the rotation of circles that have created by the following equation : 

For X Axis : <br>
<pre>
     4 <br>
  -------- * cos(n * Theta) <br>
    n PI
</pre>
 <br>
For Y Axis :  <br>
<pre>
     4  <br>
  -------- * sin(n * Theta) <br>
    n PI <br>
  
</pre> <br>

On upper equations, there three value n, PI, Theta. The n is random odd numbers and the PI is 3.1416 and Theta is rotation which have range between 0 and 2PI.

<br>
I have used SDL2 for graphics and C++ as programming language. You also do that with any other libraries and programming languages.

<strong>Note : You need to setup SDL2 with MinGW and C++ in your IDE to run this code.</strong> 
