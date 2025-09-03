---
layout: project
title: Master's Thesis on Quantum Computation using WMC
front_image:
  - url: /assets/img/projects/master-thesis.png
accent_color: "#d8eddf"
---

I finished my master in Computer Science by doing a thesis on using weighted model counting (WMC) tools to efficiently perform quantum computations. We developed a custom framework for performing matrix operations using these WMC tools, and tested its performance on several physical models.

The thesis has not yet been added to the LIACS thesis repository. Once this is the case a link to the full thesis will be added here.

## Abstract

Quantum physics and, more specifically, quantum computing have the potential to solve a myriad of problems in drug development, traffic optimization, artificial intelligence, and more. However, it is very difficult to solve these problems on a classical computer, and quantum computers are not yet equipped to solve real-world problems. As such, other techniques for solving quantum problems on classical computers have been developed recently. One of these techniques is weighted model counting (WMC), which has proven effective at a range of tasks within computer science, physics, and beyond. However, existing approaches for using WMC in physics only target specific problems, lacking a general framework for expressing problems using WMC. This limits the reusability of these approaches in other applications and means these techniques often lack mathematical rigor. We present an approach for expressing linear algebraic problems, specifically those present in physics and quantum computing, as WMC instances. We provide mathematical rigor by proving the correctness of this approach. We do this by introducing a framework that converts Dirac notation to WMC problems. We build up this framework theoretically, using a type system and denotational semantics, and provide an implementation in Python. We demonstrate the effectiveness of our framework in calculating the partition functions of several physical models: The transverse-field Ising model and the Potts model. As the performance of model counters improves in the future, our framework will provide a bridge between weighted model counting and many real-world problems.
