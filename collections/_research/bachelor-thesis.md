---
layout: project
title: Bachelor's Thesis on PDEs and Analog Computers
front_image:
  - url: /assets/img/projects/thesis-preview_300.jpg
  - url: /assets/img/projects/thesis-preview_600.jpg
    scale: 2
accent_color: "#fee2be"
---

I finished my bachlor in Computer Science and my bachelor in Mathematics at Leiden Univeristy by doing a joint thesis on partial differential equation simulation on analog computers.

{% include center-button.html href="https://theses.liacs.nl/2706" text="View full thesis" icon="link" %}

## Abstract

Analog computers can be a fast and energy-efficient way of simulating ordinary differential equations.
Simulating partial differential equations requires more work. One method is approximate all but
one of the dimensions in the PDE with a grid. This yields a large system of ODEs of the form
$\dot x = f(t, x)$. Analog computers can solve systems of this form up to a given size, depending on
the number of components available in the analog computer. To be able to solve larger systems of
ODEs, the system $\dot x = f(t, x)$ can be split up into smaller groups of equations, which may depend
on each other. To prevent having to solve all smaller systems at once, an iterative method is used.
When a value from a different group is needed, the value from the previous iteration is used.
In this thesis, a PDE-to-ODE compiler (PTOC) is introduced, which automatically converts
systems of PDEs into iterative systems of ODEs. Furthermore, it is proven that the iterative
method described above converges locally to the solution of the original system of ODEs. When $f$
has the additional property that it is Lipschitz continuous, the iterative method converges globally
to a solution. Lastly, a heuristic for dividing the system of ODEs into groups is introduced, which
aims to reduce the amount of data that needs to be stored by the analog computer. The application
of these techniques is implemented in the PTOC tool.