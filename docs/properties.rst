Properties of designs
=====================

This section shows the statistical properties of the arrays and designs generated by the Orthogonal Array package. Most properties of an array can be calculated using the :class:`~oalib.array_link`
object. Some properties are calculated using a function from the package

For example, to calculate the rank of an array and determine whether the array is a foldover array, one can use:

.. testsetup::
   
   import oapackage
   
.. admonition:: Calculate rank of array and test for foldover 

  .. doctest:: 
   
     >>> array = oapackage.exampleArray(1)
     >>> print(array.rank())
     5 
     >>> print(array.foldover())
     False

.. doxygenfunction:: array_link::rank
.. doxygenfunction:: array_link::foldover

The full set of methods can be found in the documentation of :class:`~oalib.array_link`.

Statistical properties of an array
----------------------------------

<<<<<<< HEAD
<<<<<<< HEAD
This section shows the statistical properties of the arrays and designs generated by the Orthogonal Array package. The values for most properties are vavailable from the :class:`~oalib.array_link`
object. The interface is listed below.

::

    struct array_link
    {
        ... 
        
    public:
        // statistical properties of the array

        /// calculate D-efficiency
        double Defficiency() const;
        /// calculate main effect robustness (or Ds optimality)
        double DsEfficiency(int verbose=0) const;
        /// calculate A-efficiency
        double Aefficiency() const;
        /// calculate E-efficiency
        double Eefficiency() const;
        /// calculate rank of array
        int rank() const;
        /// calculate generalized wordlength pattern
        std::vector<double> GWLP() const;
        /// return true if the array is a foldover array
        bool foldover() const;
        /// calculate centered L2 discrepancy
        double CL2discrepancy() const;
        /// Calculate the projective estimation capacity sequence
        std::vector<double> PECsequence() const;
    }
=======
=======
>>>>>>> pieter/dev
In :cite:`EendebakSO`, designs capable of estimating the interaction model are generated. To determine the best of these designs, the following efficiency criteria were used


.. doxygenfunction:: array_link::Defficiency
.. doxygenfunction:: array_link::DsEfficiency
.. doxygenfunction:: array_link::DsEfficiency
.. doxygenfunction:: array_link::Aefficiency
.. doxygenfunction:: array_link::Eefficiency

>>>>>>> eda3ae59b7a81637e44d4cf3d072fd59c47ce60a

The :math:`D`-, :math:`A`- and :math:`E`-efficiency
are calculated using the eigenvalues of
the SVD of the second order interaction
matrix. For the definition of these criteria, see Definition :ref:`DAE`. 
To calculate the rank of a matrix, the lower-upper (LU) decomposition, as
implemented in the Eigen package :cite:`eigenweb`, is used.

.. topic:: Definition: D-efficiency and average VIF
   :name: DAE

   Let :math:`X` be an :math:`N\times k` :math:`2`-level
   design with second order model :math:`{F(X)}`. Let the matrix 
   :math:`I(X) = {F(X)}^T {F(X)}` be the information matrix and let 
   :math:`\lambda_1, \ldots, \lambda_m` be its eigenvalues. The 
   :math:`{D}`-efficiency (:math:`{D(X)}`), average variance inflation factor 
   (:math:`{\mathrm{VIF}(X)}`) and :math:`{E}`-efficiency (:math:`{E(X)}`) of a design are defined as follows:

   .. math::
    
<<<<<<< HEAD
       {D(X)} = (\prod_j \lambda_j)^{1/m} / N, 
=======
       {D(X)} = (\prod_j \lambda_j)^{1/m} / N = (\det I(X) )^{1/m}, 
>>>>>>> pieter/dev
       \label{formula:Defficiency} \\
       {\mathrm{VIF}(X)} = N (\sum_j \lambda_j^{-1})/m 
       \label{formula:VIF} \\ 
       {E(X)} = \min_j \lambda_j. \label{formula:E-efficiency}

The :math:`D_s`-efficiency is the main effect robustness, see the appendix
in :cite:`Schoen2010` for more details.


Projection sequences
--------------------

For a design with :math:`N` runs and :math:`k` factors, one often studies 
projections or subdesigns with :math:`N` runs and :math:`l < k` factors. 
To determine the quality of a design in terms of its projections, one can use projection sequences.

    
.. doxygenfunction:: array_link::PECsequence
.. doxygenfunction:: PICsequence


GWLP and J-characteristics
--------------------------

From an :meth:`~oalib.array_link` object, we can calculate the generalized
worldlength patterns :cite:`Xu2001`, :math:`F`-values and
:math:`J`-characteristics.

.. admonition:: Calculate GWLP and F-values 

  .. doctest:: 
     
     >>> al=oapackage.exampleArray(1, 1)
     exampleArray 1: array 3 in OA(16, 2, 2^5)
     >>> gwlp = al.GWLP()
     >>> print('GWLP: %s'% str(gwlp) )
     GWLP: (1.0, 0.0, 0.0, 1.0, 1.0, 0.0)
     >>> print('F3-value: %s' % str(al.Fvalues(3)))
     F3-value: (4, 6)
     >>> print('F4-value: %s' % str(al.Fvalues(4)))
     F4-value: (1, 4)
     >>> print('J3-characteristics: %s' % str(al.Jcharacteristics(3)))
     J3-characteristics: (-8, -8, 0, 0, 0, -8, 0, -8, 0, 0)

The documentation:

.. doxygenfunction:: array_link::GWLP
.. doxygenfunction:: array_link::Fvalues
.. doxygenfunction:: array_link::Jcharacteristics


MD5 sums
--------

To check data structures on disk the packages includes functions to
generate MD5 sums of designs. 

.. admonition:: Calculate md5 sum of a design

  .. doctest:: 

     >>> import oapackage; al=oapackage.exampleArray(0)
     >>> al.md5()
     '6454c492239a8e01e3c01a864583abf2'

The C++ functions are:

.. doxygenfunction::  array_link::md5()
    :no-link:
.. doxygenfunction::  md5(void *, int)
    :no-link:
.. doxygenfunction::  md5(const std::string)
    :no-link:
    

    
