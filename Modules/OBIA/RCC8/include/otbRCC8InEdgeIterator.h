/*
 * Copyright (C) 2005-2017 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef otbRCC8InEdgeIterator_h
#define otbRCC8InEdgeIterator_h

#include "otbRCC8Graph.h"

namespace otb
{
/**
 * \class RCC8InEdgeIterator
 * \brief Iterates on the graph in edges from a vertex.
 *
 * \ingroup OTBRCC8
 */
template <class TGraph>
class ITK_EXPORT RCC8InEdgeIterator
{
public:
  /** self typedef */
  typedef RCC8InEdgeIterator Self;

  /** Graph typedef */
  typedef TGraph                                   GraphType;
  typedef typename GraphType::InternalGraphType    InternalGraphType;
  typedef typename GraphType::Pointer              GraphPointerType;
  typedef typename GraphType::EdgePointerType      EdgePointerType;
  typedef typename GraphType::VertexPointerType    VertexPointerType;
  typedef typename GraphType::VertexDescriptorType VertexDescriptorType;
  typedef typename GraphType::RCC8ValueType        RCC8ValueType;
  /** typedef of the internal iterator */
  typedef typename boost::graph_traits<InternalGraphType>::in_edge_iterator InternalIteratorType;
  /** Typedef of the index map */
  typedef typename boost::property_map<InternalGraphType, boost::vertex_index_t>::type IndexMapType;

  /** Constructor */
  RCC8InEdgeIterator();
  /** Copy constructor */
  RCC8InEdgeIterator(const Self &iter);
  /**  Constructor with input graph */
  RCC8InEdgeIterator(VertexDescriptorType vertex, GraphType * graph);
  /**
   * Get the current edge value.
   * \return The value of the current edge pointed by the iterator.
   */
  RCC8ValueType GetValue(void);
  /**
    * Return the source vertex of the current edge.
    * \return The source edge.
    */
  VertexPointerType GetSourceVertex(void);
  /**
   * Return the source vertex index of the current edge.
   * \return The source vertex index.
   */
  VertexDescriptorType GetSourceIndex(void);
  /**
   * Return true if the iterator is at the end.
   * \return True if the iterator is at the end.
   */
  bool IsAtEnd(void);
  /**
   * Go to the beginning.
   */
  void GoToBegin(void);
  /**
   * Increment.
   */
  Self& operator ++();
  /**
   * Decrement.
   */
  Self& operator --();
  /**
   * Add
   */
  Self& operator +(int i);

  /**
   * Remove
   */
  Self& operator -(int i);
  /**
   * Difference comparison operator.
   */
  bool operator !=(const Self& it);
  /**
   * Equality comparison operator.
   */
  bool operator ==(const Self& it);
  /**
   * Instantiation operator.
   */
  Self& operator =(const Self& it);
private:
  // End
  InternalIteratorType m_End;
  // Internal iterator.
  InternalIteratorType m_Iter;
  // Input graph pointer
  GraphPointerType m_Graph;
  // Target vertex index
  VertexDescriptorType m_VertexIndex;
};
} // End namespace otb

#ifndef OTB_MANUAL_INSTANTIATION
#include "otbRCC8InEdgeIterator.txx"
#endif

#endif
