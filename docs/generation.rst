Generation of designs
=====================


Generation of orthogonal arrays
-------------------------------

A list of arrays in LMC form can be extended to a list of arrays in LMC
form with one additional column. Details for the algorithm are described
in :raw-latex:`\cite{Eendebak2009}`.

The main function for array extension is the following:

::

    {label=C++ interface}
    /// extend a list of arrays
    arraylist_t & extend_arraylist(arraylist_t & alist, arraydata_t &fullad, 
                OAextend const &oaextendoptions);

Here \|fullad\| is the structure describing the type of arrays and
\|oaxextendoptions\| contains various options for the algorithm.

A typical session could be:

label=Extend an array >>> N=8; ncols=3; >>>
arrayclass=oapackage.arraydata\_t(2, N, 2, ncols) >>>
al=arrayclass.create\_root() >>> al.showarray() array: 0 0 0 0 0 1 0 1 1
0 1 0 1 1 1 1 >>> >>> alist=oapackage.extend\_array(al, arrayclass) >>>
for al in alist: ... al.showarray()

array: 0 0 0 0 0 0 0 1 1 0 1 1 1 0 1 1 0 1 1 1 0 1 1 0

array: 0 0 0 0 0 1 0 1 0 0 1 1 1 0 0 1 0 1 1 1 0 1 1 1

Even-odd
--------

??

Conference designs
------------------

An :math:`n\times k` conference design is an :math:`N\times k` matrix
with entries 0, -1, +1 such that i) in each column the symbol 0 occurs
exactly one time and ii) all columns are orthogonal to each other. A
more detailed description is given
in :raw-latex:`\cite{wiki:ConferenceMatrix}`.

label=Generate conference designs with 8 rows >>> import oapackage >>>
ctype=oapackage.conference\_t(N=8, k=8) >>> >>> al =
ctype.create\_root\_three() >>> al.showarray() array: 0 1 1 1 0 -1 1 1 0
1 1 1 1 1 -1 1 -1 1 1 -1 1 1 -1 -1 >>> l4=oapackage.extend\_conference (
[al], ctype, verbose=0) >>> l5=oapackage.extend\_conference ( l4, ctype,
verbose=0) >>> l6=oapackage.extend\_conference ( l5, ctype, verbose=0)
>>> >>> print(’number of non-isomorphic conference designs: number of
non-isomorphic conference designs: 11

Calculation of D-optimal designs
--------------------------------

D-optimal designs can be calculated with the function \|Doptimize\|.
This function uses a coordinate exchange algorithm to generate designs
with good properties for the :math:`D`-efficiency.

An example script with Python to generate optimal designs with 40 runs
and 7 factors is shown below.

label=Doptimize >>> N=40; s=2; k=7; >>>
arrayclass=oapackage.arraydata\_t(s, N, 0, k) >>> print(’We generate
optimal designs with: We generate optimal designs with: arrayclass: N
40, k 7, strength 0, s 2,2,2,2,2,2,2, order 0. >>> alpha=[1,2,0] >>>
method=oapackage.DOPTIM\_UPDATE >>> scores, dds, designs, ngenerated =
oapackage.Doptimize(arrayclass, nrestarts=40, optimfunc=alpha,
selectpareto=True) Doptim: optimization class 40.2-2-2-2-2-2-2
Doptimize: iteration 0/40 Doptimize: iteration 39/40 Doptim: done (8
arrays, 0.6 [s]) >>> print(’Generated 8 designs, the best D-efficiency
is 0.9098

The parameters of the function are documented in the code.

To calculate properties of designs we can use the following functions.
For :math:`D`-efficiencies we can use

::

    std::vector<double> array_link::Defficiencies ( int verbose ) const;

to calculate the :math:`D`-, :math:`D_s`- and :math:`D_1`-efficiency.
For details see :raw-latex:`\cite{EendebakSO}`.

The projective estimation capacity (PEC) sequence
from :raw-latex:`\cite{loeppky2004ranking}` can be calculated with:

::

    std::vector<double> PECsequence(const array_link &al, int verbose=1);

.. figure:: images/motivating-40-d-2-2-2-2-2-2-2-scatterplot-ndata2.png
   :alt: Scatterplot for the :math:`D`-efficiency and
   :math:`D_s`-efficiency for generated designs in
   :math:`{\operatorname{OA}(40; 2; 2^7)}`. The Pareto optimal designs
   are colored, while the non-Pareto optimal designs are grey. For
   reference the strength-3 orthogonal array with highest D-efficiency
   is also included in the plot.

   Scatterplot for the :math:`D`-efficiency and :math:`D_s`-efficiency
   for generated designs in :math:`{\operatorname{OA}(40; 2; 2^7)}`. The
   Pareto optimal designs are colored, while the non-Pareto optimal
   designs are grey. For reference the strength-3 orthogonal array with
   highest D-efficiency is also included in the plot.