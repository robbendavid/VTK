/*=========================================================================

  Program:   Visualization Toolkit
  Module:    TestLinePlot.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkSmartPointer.h"
#include "vtkChartXY.h"
#include "vtkAxis.h"
#include "vtkPlot.h"
#include "vtkTable.h"
#include "vtkFloatArray.h"
#include "vtkContextView.h"
#include "vtkContextScene.h"
#include "vtkInteractorEventRecorder.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkNew.h"
#include "vtkCompositeControlPointsItem.h"
#include "vtkPiecewiseFunction.h"
#include "vtkColorTransferFunction.h"
#include "vtkCompositeTransferFunctionItem.h"

char TestControlPointsHandleItemLog[] =
"# StreamVersion 1\n"
"RenderEvent 0 0 0 0 0 0 0\n"
"TimerEvent 0 0 0 0 0 0 0\n"
"EnterEvent 249 3 0 0 0 0 0\n"
"MouseMoveEvent 193 128 0 0 0 0 0\n"
"MouseMoveEvent 193 129 0 0 0 0 0\n"
"MouseMoveEvent 193 130 0 0 0 0 0\n"
"MouseMoveEvent 193 132 0 0 0 0 0\n"
"MouseMoveEvent 193 134 0 0 0 0 0\n"
"MouseMoveEvent 194 134 0 0 0 0 0\n"
"MouseMoveEvent 194 136 0 0 0 0 0\n"
"MouseMoveEvent 194 137 0 0 0 0 0\n"
"MouseMoveEvent 195 138 0 0 0 0 0\n"
"MouseMoveEvent 195 139 0 0 0 0 0\n"
"MouseMoveEvent 195 140 0 0 0 0 0\n"
"MouseMoveEvent 196 140 0 0 0 0 0\n"
"MouseMoveEvent 196 142 0 0 0 0 0\n"
"MouseMoveEvent 196 143 0 0 0 0 0\n"
"MouseMoveEvent 196 144 0 0 0 0 0\n"
"MouseMoveEvent 196 145 0 0 0 0 0\n"
"MouseMoveEvent 197 146 0 0 0 0 0\n"
"MouseMoveEvent 197 147 0 0 0 0 0\n"
"MouseMoveEvent 198 148 0 0 0 0 0\n"
"MouseMoveEvent 198 149 0 0 0 0 0\n"
"MouseMoveEvent 199 150 0 0 0 0 0\n"
"MouseMoveEvent 199 151 0 0 0 0 0\n"
"MouseMoveEvent 199 151 0 0 0 0 0\n"
"LeftButtonPressEvent 199 151 0 0 0 0 0\n"
"TimerEvent 199 151 0 0 0 0 0\n"
"LeftButtonReleaseEvent 199 151 0 0 0 0 0\n"
"MouseMoveEvent 199 151 0 0 0 0 0\n"
"LeftButtonPressEvent 199 151 0 0 0 0 0\n"
"LeftButtonReleaseEvent 199 151 0 0 0 0 0\n"
"LeftButtonPressEvent 199 151 0 0 0 1 0\n"
"LeftButtonReleaseEvent 199 151 0 0 0 0 0\n"
"MouseMoveEvent 199 151 0 0 0 0 0\n"
"MouseMoveEvent 199 151 0 0 0 0 0\n"
"MouseMoveEvent 200 151 0 0 0 0 0\n"
"MouseMoveEvent 202 152 0 0 0 0 0\n"
"MouseMoveEvent 202 154 0 0 0 0 0\n"
"MouseMoveEvent 204 156 0 0 0 0 0\n"
"MouseMoveEvent 206 159 0 0 0 0 0\n"
"MouseMoveEvent 212 163 0 0 0 0 0\n"
"MouseMoveEvent 222 167 0 0 0 0 0\n"
"MouseMoveEvent 231 174 0 0 0 0 0\n"
"MouseMoveEvent 243 182 0 0 0 0 0\n"
"MouseMoveEvent 253 190 0 0 0 0 0\n"
"MouseMoveEvent 263 197 0 0 0 0 0\n"
"MouseMoveEvent 274 206 0 0 0 0 0\n"
"MouseMoveEvent 284 215 0 0 0 0 0\n"
"MouseMoveEvent 289 224 0 0 0 0 0\n"
"MouseMoveEvent 297 233 0 0 0 0 0\n"
"MouseMoveEvent 304 240 0 0 0 0 0\n"
"MouseMoveEvent 308 246 0 0 0 0 0\n"
"MouseMoveEvent 313 255 0 0 0 0 0\n"
"MouseMoveEvent 319 263 0 0 0 0 0\n"
"MouseMoveEvent 323 270 0 0 0 0 0\n"
"MouseMoveEvent 326 276 0 0 0 0 0\n"
"MouseMoveEvent 331 282 0 0 0 0 0\n"
"MouseMoveEvent 334 287 0 0 0 0 0\n"
"MouseMoveEvent 337 292 0 0 0 0 0\n"
"MouseMoveEvent 341 297 0 0 0 0 0\n"
"RenderEvent 341 297  0 0 0 0 0 \n"
"TimerEvent 341 297  0 0 0 0 0 \n"
"TimerEvent 341 297  0 0 0 0 0 \n"
"TimerEvent 341 297  0 0 0 0 0 \n"
"EnterEvent 206  0 0 0 0 0 0 \n"
"MouseMoveEvent 206  0 0 0 0 0 0 \n"
"MouseMoveEvent 205 9  0 0 0 0 0 \n"
"MouseMoveEvent 205 18  0 0 0 0 0 \n"
"MouseMoveEvent 204 27  0 0 0 0 0 \n"
"MouseMoveEvent 203 36  0 0 0 0 0 \n"
"MouseMoveEvent 203 42  0 0 0 0 0 \n"
"MouseMoveEvent 203 51  0 0 0 0 0 \n"
"MouseMoveEvent 203 55  0 0 0 0 0 \n"
"MouseMoveEvent 203 62  0 0 0 0 0 \n"
"MouseMoveEvent 203 65  0 0 0 0 0 \n"
"MouseMoveEvent 203 72  0 0 0 0 0 \n"
"MouseMoveEvent 204 76  0 0 0 0 0 \n"
"MouseMoveEvent 205 81  0 0 0 0 0 \n"
"MouseMoveEvent 206 85  0 0 0 0 0 \n"
"MouseMoveEvent 207 9 0 0 0 0 0 0 \n"
"MouseMoveEvent 208 93  0 0 0 0 0 \n"
"MouseMoveEvent 208 96  0 0 0 0 0 \n"
"MouseMoveEvent 208 98  0 0 0 0 0 \n"
"MouseMoveEvent 209 10 0 0 0 0 0 0 \n"
"MouseMoveEvent 209 102  0 0 0 0 0 \n"
"MouseMoveEvent 209 103  0 0 0 0 0 \n"
"MouseMoveEvent 209 105  0 0 0 0 0 \n"
"MouseMoveEvent 210 108  0 0 0 0 0 \n"
"MouseMoveEvent 210 108  0 0 0 0 0 \n"
"MouseMoveEvent 210 111  0 0 0 0 0 \n"
"MouseMoveEvent 211 114  0 0 0 0 0 \n"
"MouseMoveEvent 211 115  0 0 0 0 0 \n"
"MouseMoveEvent 211 118  0 0 0 0 0 \n"
"MouseMoveEvent 211 121  0 0 0 0 0 \n"
"MouseMoveEvent 210 124  0 0 0 0 0 \n"
"MouseMoveEvent 210 125  0 0 0 0 0 \n"
"MouseMoveEvent 209 126  0 0 0 0 0 \n"
"MouseMoveEvent 209 127  0 0 0 0 0 \n"
"MouseMoveEvent 209 128  0 0 0 0 0 \n"
"MouseMoveEvent 208 128  0 0 0 0 0 \n"
"MouseMoveEvent 207 129  0 0 0 0 0 \n"
"MouseMoveEvent 207 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 206 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 206 131  0 0 0 0 0 \n"
"MouseMoveEvent 206 132  0 0 0 0 0 \n"
"MouseMoveEvent 205 133  0 0 0 0 0 \n"
"MouseMoveEvent 204 134  0 0 0 0 0 \n"
"MouseMoveEvent 203 135  0 0 0 0 0 \n"
"MouseMoveEvent 203 136  0 0 0 0 0 \n"
"MouseMoveEvent 202 136  0 0 0 0 0 \n"
"MouseMoveEvent 201 137  0 0 0 0 0 \n"
"MouseMoveEvent 201 138  0 0 0 0 0 \n"
"TimerEvent 201 138  0 0 0 0 0 \n"
"MouseMoveEvent 200 138  0 0 0 0 0 \n"
"MouseMoveEvent 199 138  0 0 0 0 0 \n"
"MouseMoveEvent 198 138  0 0 0 0 0 \n"
"MouseMoveEvent 198 139  0 0 0 0 0 \n"
"MouseMoveEvent 199 139  0 0 0 0 0 \n"
"LeftButtonPressEvent 199 139  0 0 0 0 0 \n"
"MouseMoveEvent 199 139  0 0 0 0 0 \n"
"TimerEvent 199 139  0 0 0 0 0 \n"
"MouseMoveEvent 199 138  0 0 0 0 0 \n"
"MouseMoveEvent 199 137  0 0 0 0 0 \n"
"MouseMoveEvent 199 136  0 0 0 0 0 \n"
"TimerEvent 199 136  0 0 0 0 0 \n"
"MouseMoveEvent 199 135  0 0 0 0 0 \n"
"TimerEvent 199 135  0 0 0 0 0 \n"
"MouseMoveEvent 199 134  0 0 0 0 0 \n"
"TimerEvent 199 134  0 0 0 0 0 \n"
"MouseMoveEvent 199 133  0 0 0 0 0 \n"
"MouseMoveEvent 198 133  0 0 0 0 0 \n"
"TimerEvent 198 133  0 0 0 0 0 \n"
"MouseMoveEvent 198 132  0 0 0 0 0 \n"
"MouseMoveEvent 198 131  0 0 0 0 0 \n"
"TimerEvent 198 131  0 0 0 0 0 \n"
"MouseMoveEvent 198 13 0 0 0 0 0 0 \n"
"TimerEvent 198 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 198 13 0 0 0 0 0 0 \n"
"TimerEvent 198 13 0 0 0 0 0 0 \n"
"LeftButtonReleaseEvent 198 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 198 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 197 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 196 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 195 129  0 0 0 0 0 \n"
"TimerEvent 195 129  0 0 0 0 0 \n"
"MouseMoveEvent 194 129  0 0 0 0 0 \n"
"MouseMoveEvent 193 129  0 0 0 0 0 \n"
"MouseMoveEvent 193 128  0 0 0 0 0 \n"
"MouseMoveEvent 192 128  0 0 0 0 0 \n"
"MouseMoveEvent 193 128  0 0 0 0 0 \n"
"MouseMoveEvent 193 129  0 0 0 0 0 \n"
"MouseMoveEvent 193 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 194 13 0 0 0 0 0 0 \n"
"MouseMoveEvent 194 131  0 0 0 0 0 \n"
"MouseMoveEvent 194 132  0 0 0 0 0 \n"
"MouseMoveEvent 194 133  0 0 0 0 0 \n"
"MouseMoveEvent 194 134  0 0 0 0 0 \n"
"MouseMoveEvent 194 135  0 0 0 0 0 \n"
"MouseMoveEvent 194 135  0 0 0 0 0 \n"
"MouseMoveEvent 194 136  0 0 0 0 0 \n"
"MouseMoveEvent 194 138  0 0 0 0 0 \n"
"MouseMoveEvent 194 139  0 0 0 0 0 \n"
"MouseMoveEvent 194 14 0 0 0 0 0 0 \n"
"MouseMoveEvent 194 141  0 0 0 0 0 \n"
"MouseMoveEvent 194 142  0 0 0 0 0 \n"
"MouseMoveEvent 194 143  0 0 0 0 0 \n"
"MouseMoveEvent 194 145  0 0 0 0 0 \n"
"MouseMoveEvent 194 146  0 0 0 0 0 \n"
"MouseMoveEvent 194 147  0 0 0 0 0 \n"
"MouseMoveEvent 194 148  0 0 0 0 0 \n"
"MouseMoveEvent 194 149  0 0 0 0 0 \n"
"MouseMoveEvent 194 15 0 0 0 0 0 0 \n"
"MouseMoveEvent 194 151  0 0 0 0 0 \n"
"MouseMoveEvent 194 152  0 0 0 0 0 \n"
"MouseMoveEvent 194 153  0 0 0 0 0 \n"
"MouseMoveEvent 194 154  0 0 0 0 0 \n"
"MouseMoveEvent 194 155  0 0 0 0 0 \n"
"MouseMoveEvent 194 156  0 0 0 0 0 \n"
"MouseMoveEvent 194 158  0 0 0 0 0 \n"
"MouseMoveEvent 194 159  0 0 0 0 0 \n"
"MouseMoveEvent 194 16 0 0 0 0 0 0 \n"
"MouseMoveEvent 195 161  0 0 0 0 0 \n"
"MouseMoveEvent 196 161  0 0 0 0 0 \n"
"TimerEvent 196 161  0 0 0 0 0 \n"
"MouseMoveEvent 196 162  0 0 0 0 0 \n"
"TimerEvent 196 162  0 0 0 0 0 \n"
"MouseMoveEvent 197 162  0 0 0 0 0 \n"
"TimerEvent 197 162  0 0 0 0 0 \n"
"MouseMoveEvent 198 162  0 0 0 0 0 \n"
"MouseMoveEvent 198 162  0 0 0 0 0 \n"
"MouseMoveEvent 199 162  0 0 0 0 0 \n"
"MouseMoveEvent 199 161  0 0 0 0 0 \n"
"MouseMoveEvent 199 16 0 0 0 0 0 0 \n"
"MouseMoveEvent 199 159  0 0 0 0 0 \n"
"LeftButtonPressEvent 199 159  0 0 0 0 0 \n"
"MouseMoveEvent 199 159  0 0 0 0 0 \n"
"MouseMoveEvent 199 16 0 0 0 0 0 0 \n"
"MouseMoveEvent 199 161  0 0 0 0 0 \n"
"MouseMoveEvent 199 162  0 0 0 0 0 \n"
"MouseMoveEvent 199 163  0 0 0 0 0 \n"
"TimerEvent 199 163  0 0 0 0 0 \n"
"MouseMoveEvent 200 163  0 0 0 0 0 \n"
"MouseMoveEvent 200 164  0 0 0 0 0 \n"
"MouseMoveEvent 200 165  0 0 0 0 0 \n"
"MouseMoveEvent 200 166  0 0 0 0 0 \n"
"TimerEvent 200 166  0 0 0 0 0 \n"
"MouseMoveEvent 200 167  0 0 0 0 0 \n"
"MouseMoveEvent 201 167  0 0 0 0 0 \n"
"MouseMoveEvent 201 168  0 0 0 0 0 \n"
"TimerEvent 201 168  0 0 0 0 0 \n"
"MouseMoveEvent 201 169  0 0 0 0 0 \n"
"TimerEvent 201 169  0 0 0 0 0 \n"
"MouseMoveEvent 201 17 0 0 0 0 0 0 \n"
"TimerEvent 201 17 0 0 0 0 0 0 \n"
"MouseMoveEvent 201 171  0 0 0 0 0 \n"
"TimerEvent 201 171  0 0 0 0 0 \n"
"MouseMoveEvent 201 171  0 0 0 0 0 \n"
"TimerEvent 201 171  0 0 0 0 0 \n"
"LeftButtonReleaseEvent 201 171  0 0 0 0 0 \n"
"MouseMoveEvent 201 171  0 0 0 0 0 \n"
"MouseMoveEvent 201 172  0 0 0 0 0 \n"
"TimerEvent 201 172  0 0 0 0 0 \n"
"MouseMoveEvent 200 172  0 0 0 0 0 \n"
"MouseMoveEvent 200 171  0 0 0 0 0 \n"
"MouseMoveEvent 200 17 0 0 0 0 0 0 \n"
"MouseMoveEvent 200 169  0 0 0 0 0 \n"
"MouseMoveEvent 199 169  0 0 0 0 0 \n"
"MouseMoveEvent 199 168  0 0 0 0 0 \n"
"MouseMoveEvent 199 167  0 0 0 0 0 \n"
"MouseMoveEvent 199 166  0 0 0 0 0 \n"
"TimerEvent 199 166  0 0 0 0 0 \n"
"MouseMoveEvent 200 168  0 0 0 0 0 \n"
"MouseMoveEvent 201 169  0 0 0 0 0 \n"
"MouseMoveEvent 204 171  0 0 0 0 0 \n"
"MouseMoveEvent 205 172  0 0 0 0 0 \n"
"MouseMoveEvent 206 172  0 0 0 0 0 \n"
"MouseMoveEvent 207 172  0 0 0 0 0 \n"
"TimerEvent 207 172  0 0 0 0 0 \n"
"MouseMoveEvent 207 173  0 0 0 0 0 \n"
"MouseMoveEvent 208 173  0 0 0 0 0 \n"
"MouseMoveEvent 209 173  0 0 0 0 0 \n"
"MouseMoveEvent 210 173  0 0 0 0 0 \n"
"MouseMoveEvent 211 175  0 0 0 0 0 \n"
"MouseMoveEvent 212 175  0 0 0 0 0 \n"
"MouseMoveEvent 213 176  0 0 0 0 0 \n"
"MouseMoveEvent 213 177  0 0 0 0 0 \n"
"MouseMoveEvent 213 179  0 0 0 0 0 \n"
"MouseMoveEvent 213 18 0 0 0 0 0 0 \n"
"MouseMoveEvent 213 181  0 0 0 0 0 \n"
"MouseMoveEvent 213 182  0 0 0 0 0 \n"
"MouseMoveEvent 213 185  0 0 0 0 0 \n"
"MouseMoveEvent 214 187  0 0 0 0 0 \n"
"MouseMoveEvent 215 189  0 0 0 0 0 \n"
"MouseMoveEvent 215 191  0 0 0 0 0 \n"
"MouseMoveEvent 216 194  0 0 0 0 0 \n"
"MouseMoveEvent 216 195  0 0 0 0 0 \n"
"MouseMoveEvent 216 199  0 0 0 0 0 \n"
"MouseMoveEvent 217 203  0 0 0 0 0 \n"
"MouseMoveEvent 218 208  0 0 0 0 0 \n"
"MouseMoveEvent 218 211  0 0 0 0 0 \n"
"MouseMoveEvent 219 215  0 0 0 0 0 \n"
"MouseMoveEvent 221 221  0 0 0 0 0 \n"
"MouseMoveEvent 222 224  0 0 0 0 0 \n"
"MouseMoveEvent 222 227  0 0 0 0 0 \n"
"MouseMoveEvent 223 23 0 0 0 0 0 0 \n"
"MouseMoveEvent 223 232  0 0 0 0 0 \n"
"MouseMoveEvent 223 234  0 0 0 0 0 \n"
"MouseMoveEvent 224 236  0 0 0 0 0 \n"
"MouseMoveEvent 225 238  0 0 0 0 0 \n"
"MouseMoveEvent 226 24 0 0 0 0 0 0 \n"
"MouseMoveEvent 226 242  0 0 0 0 0 \n"
"MouseMoveEvent 227 244  0 0 0 0 0 \n"
"MouseMoveEvent 228 246  0 0 0 0 0 \n"
"MouseMoveEvent 228 247  0 0 0 0 0 \n"
"MouseMoveEvent 228 248  0 0 0 0 0 \n"
"MouseMoveEvent 229 25 0 0 0 0 0 0 \n"
"MouseMoveEvent 230 251  0 0 0 0 0 \n"
"MouseMoveEvent 230 252  0 0 0 0 0 \n"
"MouseMoveEvent 230 254  0 0 0 0 0 \n"
"MouseMoveEvent 231 255  0 0 0 0 0 \n"
"MouseMoveEvent 231 255  0 0 0 0 0 \n"
"MouseMoveEvent 232 256  0 0 0 0 0 \n"
"MouseMoveEvent 232 257  0 0 0 0 0 \n"
"MouseMoveEvent 234 257  0 0 0 0 0 \n"
"MouseMoveEvent 235 258  0 0 0 0 0 \n"
"MouseMoveEvent 236 258  0 0 0 0 0 \n"
"MouseMoveEvent 237 258  0 0 0 0 0 \n"
"MouseMoveEvent 238 258  0 0 0 0 0 \n"
"MouseMoveEvent 239 259  0 0 0 0 0 \n"
"MouseMoveEvent 240 259  0 0 0 0 0 \n"
"MouseMoveEvent 241 259  0 0 0 0 0 \n"
"MouseMoveEvent 241 26 0 0 0 0 0 0 \n"
"MouseMoveEvent 242 261  0 0 0 0 0 \n"
"MouseMoveEvent 243 262  0 0 0 0 0 \n"
"MouseMoveEvent 244 262  0 0 0 0 0 \n"
"MouseMoveEvent 244 263  0 0 0 0 0 \n"
"MouseMoveEvent 245 264  0 0 0 0 0 \n"
"MouseMoveEvent 244 264  0 0 0 0 0 \n"
"MouseMoveEvent 244 264  0 0 0 0 0 \n"
"MouseMoveEvent 244 263  0 0 0 0 0 \n"
"MouseMoveEvent 243 263  0 0 0 0 0 \n"
"MouseMoveEvent 242 263  0 0 0 0 0 \n"
"MouseMoveEvent 241 263  0 0 0 0 0 \n"
"MouseMoveEvent 240 263  0 0 0 0 0 \n"
"MouseMoveEvent 240 262  0 0 0 0 0 \n"
"MouseMoveEvent 239 262  0 0 0 0 0 \n"
"MouseMoveEvent 238 261  0 0 0 0 0 \n"
"MouseMoveEvent 237 26 0 0 0 0 0 0 \n"
"MouseMoveEvent 237 259  0 0 0 0 0 \n"
"MouseMoveEvent 237 259  0 0 0 0 0 \n"
"MouseMoveEvent 238 259  0 0 0 0 0 \n"
"MouseMoveEvent 239 259  0 0 0 0 0 \n"
"MouseMoveEvent 240 26 0 0 0 0 0 0 \n"
"MouseMoveEvent 241 26 0 0 0 0 0 0 \n"
"MouseMoveEvent 241 261  0 0 0 0 0 \n"
"MouseMoveEvent 242 261  0 0 0 0 0 \n"
"MouseMoveEvent 243 261  0 0 0 0 0 \n"
"MouseMoveEvent 243 262  0 0 0 0 0 \n"
"MouseMoveEvent 244 262  0 0 0 0 0 \n"
"MouseMoveEvent 245 262  0 0 0 0 0 \n"
"MouseMoveEvent 246 263  0 0 0 0 0 \n"
"MouseMoveEvent 246 261  0 0 0 0 0 \n"
"MouseMoveEvent 246 259  0 0 0 0 0 \n"
"MouseMoveEvent 246 258  0 0 0 0 0 \n"
"MouseMoveEvent 246 256  0 0 0 0 0 \n"
"MouseMoveEvent 246 254  0 0 0 0 0 \n"
"MouseMoveEvent 246 253  0 0 0 0 0 \n"
"MouseMoveEvent 246 252  0 0 0 0 0 \n"
"MouseMoveEvent 246 251  0 0 0 0 0 \n"
"MouseMoveEvent 246 25 0 0 0 0 0 0 \n"
"MouseMoveEvent 246 249  0 0 0 0 0 \n"
"MouseMoveEvent 246 248  0 0 0 0 0 \n"
"MouseMoveEvent 246 247  0 0 0 0 0 \n"
"MouseMoveEvent 246 246  0 0 0 0 0 \n"
"MouseMoveEvent 246 245  0 0 0 0 0 \n"
"MouseMoveEvent 246 243  0 0 0 0 0 \n"
"MouseMoveEvent 246 242  0 0 0 0 0 \n"
"MouseMoveEvent 245 241  0 0 0 0 0 \n"
"MouseMoveEvent 245 24 0 0 0 0 0 0 \n"
"MouseMoveEvent 245 238  0 0 0 0 0 \n"
"MouseMoveEvent 244 235  0 0 0 0 0 \n"
"MouseMoveEvent 243 233  0 0 0 0 0 \n"
"MouseMoveEvent 242 229  0 0 0 0 0 \n"
"MouseMoveEvent 240 225  0 0 0 0 0 \n"
"MouseMoveEvent 240 221  0 0 0 0 0 \n"
"MouseMoveEvent 238 215  0 0 0 0 0 \n"
"MouseMoveEvent 236 21 0 0 0 0 0 0 \n"
"MouseMoveEvent 235 205  0 0 0 0 0 \n"
"MouseMoveEvent 233 199  0 0 0 0 0 \n"
"MouseMoveEvent 232 194  0 0 0 0 0 \n"
"MouseMoveEvent 230 19 0 0 0 0 0 0 \n"
"MouseMoveEvent 228 185  0 0 0 0 0 \n"
"MouseMoveEvent 227 181  0 0 0 0 0 \n"
"MouseMoveEvent 227 178  0 0 0 0 0 \n"
"MouseMoveEvent 227 174  0 0 0 0 0 \n"
"MouseMoveEvent 227 171  0 0 0 0 0 \n"
"MouseMoveEvent 227 169  0 0 0 0 0 \n"
"MouseMoveEvent 227 168  0 0 0 0 0 \n"
"MouseMoveEvent 227 167  0 0 0 0 0 \n"
"MouseMoveEvent 228 165  0 0 0 0 0 \n"
"MouseMoveEvent 229 163  0 0 0 0 0 \n"
"MouseMoveEvent 229 162  0 0 0 0 0 \n"
"MouseMoveEvent 229 161  0 0 0 0 0 \n"
"MouseMoveEvent 229 159  0 0 0 0 0 \n"
"MouseMoveEvent 229 158  0 0 0 0 0 \n"
"MouseMoveEvent 229 157  0 0 0 0 0 \n"
"MouseMoveEvent 230 156  0 0 0 0 0 \n"
"MouseMoveEvent 230 155  0 0 0 0 0 \n"
"MouseMoveEvent 230 154  0 0 0 0 0 \n"
"MouseMoveEvent 230 153  0 0 0 0 0 \n"
"MouseMoveEvent 231 152  0 0 0 0 0 \n"
"MouseMoveEvent 231 15 0 0 0 0 0 0 \n"
"MouseMoveEvent 232 148  0 0 0 0 0 \n"
"MouseMoveEvent 232 147  0 0 0 0 0 \n"
"MouseMoveEvent 233 145  0 0 0 0 0 \n"
"TimerEvent 233 145  0 0 0 0 0 \n"
"MouseMoveEvent 233 143  0 0 0 0 0 \n"
"MouseMoveEvent 233 142  0 0 0 0 0 \n"
"MouseMoveEvent 233 142  0 0 0 0 0 \n"
"MouseMoveEvent 233 141  0 0 0 0 0 \n"
"MouseMoveEvent 233 14 0 0 0 0 0 0 \n"
"MouseMoveEvent 233 139  0 0 0 0 0 \n"
"MouseMoveEvent 233 138  0 0 0 0 0 \n"
"MouseMoveEvent 234 138  0 0 0 0 0 \n"
"MouseMoveEvent 234 139  0 0 0 0 0 \n"
"MouseMoveEvent 234 14 0 0 0 0 0 0 \n"
"MouseMoveEvent 235 141  0 0 0 0 0 \n"
"MouseMoveEvent 235 142  0 0 0 0 0 \n"
"MouseMoveEvent 235 143  0 0 0 0 0 \n"
"MouseMoveEvent 235 144  0 0 0 0 0 \n"
"MouseMoveEvent 235 145  0 0 0 0 0 \n"
"MouseMoveEvent 235 146  0 0 0 0 0 \n"
"MouseMoveEvent 235 147  0 0 0 0 0 \n"
"MouseMoveEvent 235 148  0 0 0 0 0 \n"
"TimerEvent 235 148  0 0 0 0 0 \n"
"MouseMoveEvent 235 15 0 0 0 0 0 0 \n"
"MouseMoveEvent 235 151  0 0 0 0 0 \n"
"MouseMoveEvent 235 152  0 0 0 0 0 \n"
"MouseMoveEvent 234 152  0 0 0 0 0 \n"
"MouseMoveEvent 233 152  0 0 0 0 0 \n"
"MouseMoveEvent 232 152  0 0 0 0 0 \n"
"MouseMoveEvent 231 152  0 0 0 0 0 \n"
"MouseMoveEvent 231 151  0 0 0 0 0 \n"
"MouseMoveEvent 231 15 0 0 0 0 0 0 \n"
"MouseMoveEvent 231 15 0 0 0 0 0 0 \n"
"LeftButtonPressEvent 231 15 0 0 0 0 0 0 \n"
"MouseMoveEvent 231 149  0 0 0 0 0 \n"
"MouseMoveEvent 230 149  0 0 0 0 0 \n"
"TimerEvent 230 149  0 0 0 0 0 \n"
"MouseMoveEvent 229 148  0 0 0 0 0 \n"
"MouseMoveEvent 228 148  0 0 0 0 0 \n"
"TimerEvent 228 148  0 0 0 0 0 \n"
"MouseMoveEvent 227 148  0 0 0 0 0 \n"
"MouseMoveEvent 227 148  0 0 0 0 0 \n"
"MouseMoveEvent 226 147  0 0 0 0 0 \n"
"TimerEvent 226 147  0 0 0 0 0 \n"
"MouseMoveEvent 225 147  0 0 0 0 0 \n"
"TimerEvent 225 147  0 0 0 0 0 \n"
"MouseMoveEvent 224 147  0 0 0 0 0 \n"
"MouseMoveEvent 224 146  0 0 0 0 0 \n"
"LeftButtonReleaseEvent 224 146  0 0 0 0 0 \n"
"MouseMoveEvent 224 146  0 0 0 0 0 \n"
"TimerEvent 224 146  0 0 0 0 0 \n"
"MouseMoveEvent 223 146  0 0 0 0 0 \n"
"MouseMoveEvent 223 145  0 0 0 0 0 \n"
"MouseMoveEvent 222 145  0 0 0 0 0 \n"
"MouseMoveEvent 221 144  0 0 0 0 0 \n"
"TimerEvent 221 144  0 0 0 0 0 \n"
"MouseMoveEvent 220 144  0 0 0 0 0 \n"
"MouseMoveEvent 220 142  0 0 0 0 0 \n"
"MouseMoveEvent 219 142  0 0 0 0 0 \n"
"MouseMoveEvent 219 14 0 0 0 0 0 0 \n"
"MouseMoveEvent 217 14 0 0 0 0 0 0 \n"
"MouseMoveEvent 216 138  0 0 0 0 0 \n"
"MouseMoveEvent 215 138  0 0 0 0 0 \n"
"MouseMoveEvent 214 137  0 0 0 0 0 \n"
"MouseMoveEvent 212 136  0 0 0 0 0 \n"
"MouseMoveEvent 211 136  0 0 0 0 0 \n"
"MouseMoveEvent 209 135  0 0 0 0 0 \n"
"MouseMoveEvent 207 134  0 0 0 0 0 \n"
"MouseMoveEvent 204 134  0 0 0 0 0 \n"
"MouseMoveEvent 202 133  0 0 0 0 0 \n"
"MouseMoveEvent 199 133  0 0 0 0 0 \n"
"MouseMoveEvent 198 133  0 0 0 0 0 \n"
"MouseMoveEvent 197 133  0 0 0 0 0 \n"
"MouseMoveEvent 196 133  0 0 0 0 0 \n"
"MouseMoveEvent 195 133  0 0 0 0 0 \n"
"TimerEvent 195 133  0 0 0 0 0 \n"
"MouseMoveEvent 194 133  0 0 0 0 0 \n"
"MouseMoveEvent 193 133  0 0 0 0 0 \n"
"MouseMoveEvent 192 133  0 0 0 0 0 \n"
"MouseMoveEvent 191 133  0 0 0 0 0 \n"
"MouseMoveEvent 190 133  0 0 0 0 0 \n"
"MouseMoveEvent 189 133  0 0 0 0 0 \n"
"MouseMoveEvent 187 133  0 0 0 0 0 \n"
"MouseMoveEvent 187 134  0 0 0 0 0 \n"
"MouseMoveEvent 186 134  0 0 0 0 0 \n"
"MouseMoveEvent 185 134  0 0 0 0 0 \n"
"MouseMoveEvent 184 134  0 0 0 0 0 \n"
"MouseMoveEvent 184 135  0 0 0 0 0 \n"
"MouseMoveEvent 183 135  0 0 0 0 0 \n"
"MouseMoveEvent 182 135  0 0 0 0 0 \n"
"MouseMoveEvent 181 136  0 0 0 0 0 \n"
"MouseMoveEvent 180 136  0 0 0 0 0 \n"
"MouseMoveEvent 179 137  0 0 0 0 0 \n"
"MouseMoveEvent 178 137  0 0 0 0 0 \n"
"MouseMoveEvent 177 137  0 0 0 0 0 \n"
"MouseMoveEvent 176 137  0 0 0 0 0 \n"
"MouseMoveEvent 175 137  0 0 0 0 0 \n"
"MouseMoveEvent 175 138  0 0 0 0 0 \n"
"MouseMoveEvent 173 138  0 0 0 0 0 \n"
"MouseMoveEvent 170 139  0 0 0 0 0 \n"
"MouseMoveEvent 169 139  0 0 0 0 0 \n"
"MouseMoveEvent 168 139  0 0 0 0 0 \n"
"MouseMoveEvent 167 14 0 0 0 0 0 0 \n"
"MouseMoveEvent 167 14 0 0 0 0 0 0 \n"
"MouseMoveEvent 165 142  0 0 0 0 0 \n"
"MouseMoveEvent 165 143  0 0 0 0 0 \n"
"MouseMoveEvent 164 144  0 0 0 0 0 \n"
"MouseMoveEvent 164 145  0 0 0 0 0 \n"
"MouseMoveEvent 163 145  0 0 0 0 0 \n"
"MouseMoveEvent 163 146  0 0 0 0 0 \n"
"MouseMoveEvent 163 147  0 0 0 0 0 \n"
"MouseMoveEvent 163 148  0 0 0 0 0 \n"
"TimerEvent 163 148  0 0 0 0 0 \n"
"MouseMoveEvent 164 148  0 0 0 0 0 \n"
"MouseMoveEvent 165 148  0 0 0 0 0 \n"
"MouseMoveEvent 166 148  0 0 0 0 0 \n"
"MouseMoveEvent 166 149  0 0 0 0 0 \n"
"MouseMoveEvent 167 149  0 0 0 0 0 \n"
"LeftButtonPressEvent 167 149  0 0 0 0 0 \n"
"MouseMoveEvent 167 149  0 0 0 0 0 \n"
"TimerEvent 167 149  0 0 0 0 0 \n"
"MouseMoveEvent 168 149  0 0 0 0 0 \n"
"TimerEvent 168 149  0 0 0 0 0 \n"
"MouseMoveEvent 169 149  0 0 0 0 0 \n"
"MouseMoveEvent 170 149  0 0 0 0 0 \n"
"MouseMoveEvent 171 149  0 0 0 0 0 \n"
"TimerEvent 171 149  0 0 0 0 0 \n"
"MouseMoveEvent 172 149  0 0 0 0 0 \n"
"MouseMoveEvent 172 149  0 0 0 0 0 \n"
"MouseMoveEvent 173 149  0 0 0 0 0 \n"
"TimerEvent 173 149  0 0 0 0 0 \n"
"MouseMoveEvent 174 149  0 0 0 0 0 \n"
"MouseMoveEvent 174 148  0 0 0 0 0 \n"
"TimerEvent 174 148  0 0 0 0 0 \n"
"MouseMoveEvent 175 148  0 0 0 0 0 \n"
"TimerEvent 175 148  0 0 0 0 0 \n"
"MouseMoveEvent 176 148  0 0 0 0 0 \n"
"TimerEvent 176 148  0 0 0 0 0 \n"
"MouseMoveEvent 177 148  0 0 0 0 0 \n"
"TimerEvent 177 148  0 0 0 0 0 \n"
"LeftButtonReleaseEvent 177 148  0 0 0 0 0 \n"
"MouseMoveEvent 177 148  0 0 0 0 0 \n"
"TimerEvent 177 148  0 0 0 0 0 \n"
"MouseMoveEvent 177 147  0 0 0 0 0 \n"
"MouseMoveEvent 176 147  0 0 0 0 0 \n"
"MouseMoveEvent 176 146  0 0 0 0 0 \n"
"MouseMoveEvent 175 146  0 0 0 0 0 \n"
"MouseMoveEvent 176 146  0 0 0 0 0 \n"
"MouseMoveEvent 177 146  0 0 0 0 0 \n"
"MouseMoveEvent 178 147  0 0 0 0 0 \n"
"MouseMoveEvent 180 147  0 0 0 0 0 \n"
"MouseMoveEvent 182 148  0 0 0 0 0 \n"
"MouseMoveEvent 185 15 0 0 0 0 0 0 \n"
"MouseMoveEvent 185 15 0 0 0 0 0 0 \n"
"MouseMoveEvent 187 151  0 0 0 0 0 \n"
"MouseMoveEvent 189 153  0 0 0 0 0 \n"
"MouseMoveEvent 193 155  0 0 0 0 0 \n"
"TimerEvent 193 155  0 0 0 0 0 \n"
"MouseMoveEvent 198 159  0 0 0 0 0 \n"
"MouseMoveEvent 202 162  0 0 0 0 0 \n"
"MouseMoveEvent 206 164  0 0 0 0 0 \n"
"MouseMoveEvent 212 168  0 0 0 0 0 \n"
"MouseMoveEvent 217 17 0 0 0 0 0 0 \n"
"MouseMoveEvent 222 172  0 0 0 0 0 \n"
"MouseMoveEvent 230 175  0 0 0 0 0 \n"
"MouseMoveEvent 240 178  0 0 0 0 0 \n"
"MouseMoveEvent 247 179  0 0 0 0 0 \n"
"MouseMoveEvent 254 183  0 0 0 0 0 \n"
"MouseMoveEvent 263 184  0 0 0 0 0 \n"
"MouseMoveEvent 268 186  0 0 0 0 0 \n"
"MouseMoveEvent 273 188  0 0 0 0 0 \n"
"MouseMoveEvent 278 19 0 0 0 0 0 0 \n"
"MouseMoveEvent 281 192  0 0 0 0 0 \n"
"MouseMoveEvent 283 192  0 0 0 0 0 \n"
"MouseMoveEvent 287 194  0 0 0 0 0 \n"
"MouseMoveEvent 290 196  0 0 0 0 0 \n"
"MouseMoveEvent 292 197  0 0 0 0 0 \n"
"MouseMoveEvent 296 199  0 0 0 0 0 \n"
"MouseMoveEvent 298 201  0 0 0 0 0 \n"
"MouseMoveEvent 301 202  0 0 0 0 0 \n"
"MouseMoveEvent 303 204  0 0 0 0 0 \n"
"MouseMoveEvent 306 205  0 0 0 0 0 \n"
"MouseMoveEvent 308 208  0 0 0 0 0 \n"
"MouseMoveEvent 310 208  0 0 0 0 0 \n"
"MouseMoveEvent 313 21 0 0 0 0 0 0 \n"
"MouseMoveEvent 314 211  0 0 0 0 0 \n"
"MouseMoveEvent 316 213  0 0 0 0 0 \n"
"MouseMoveEvent 318 214  0 0 0 0 0 \n"
"MouseMoveEvent 319 216  0 0 0 0 0 \n"
"MouseMoveEvent 320 216  0 0 0 0 0 \n"
"MouseMoveEvent 320 218  0 0 0 0 0 \n"
"MouseMoveEvent 322 22 0 0 0 0 0 0 \n"
"MouseMoveEvent 323 222  0 0 0 0 0 \n"
"MouseMoveEvent 324 225  0 0 0 0 0 \n"
"MouseMoveEvent 325 227  0 0 0 0 0 \n"
"MouseMoveEvent 326 228  0 0 0 0 0 \n"
"MouseMoveEvent 327 23 0 0 0 0 0 0 \n"
"MouseMoveEvent 327 232  0 0 0 0 0 \n"
"MouseMoveEvent 328 234  0 0 0 0 0 \n"
"MouseMoveEvent 329 236  0 0 0 0 0 \n"
"MouseMoveEvent 330 239  0 0 0 0 0 \n"
"MouseMoveEvent 331 24 0 0 0 0 0 0 \n"
"MouseMoveEvent 332 243  0 0 0 0 0 \n"
"MouseMoveEvent 333 246  0 0 0 0 0 \n"
"MouseMoveEvent 334 248  0 0 0 0 0 \n"
"MouseMoveEvent 335 25 0 0 0 0 0 0 \n"
"MouseMoveEvent 336 252  0 0 0 0 0 \n"
"MouseMoveEvent 337 254  0 0 0 0 0 \n"
"MouseMoveEvent 337 256  0 0 0 0 0 \n"
"MouseMoveEvent 339 258  0 0 0 0 0 \n"
"MouseMoveEvent 340 261  0 0 0 0 0 \n"
"MouseMoveEvent 341 263  0 0 0 0 0 \n"
"MouseMoveEvent 343 265  0 0 0 0 0 \n"
"MouseMoveEvent 344 267  0 0 0 0 0 \n"
"MouseMoveEvent 344 269  0 0 0 0 0 \n"
"MouseMoveEvent 346 272  0 0 0 0 0 \n"
"MouseMoveEvent 347 273  0 0 0 0 0 \n"
"MouseMoveEvent 348 276  0 0 0 0 0 \n"
"MouseMoveEvent 349 278  0 0 0 0 0 \n"
"MouseMoveEvent 350 28 0 0 0 0 0 0 \n"
"MouseMoveEvent 352 282  0 0 0 0 0 \n"
"MouseMoveEvent 353 285  0 0 0 0 0 \n"
"MouseMoveEvent 353 286  0 0 0 0 0 \n"
"MouseMoveEvent 355 288  0 0 0 0 0 \n"
"MouseMoveEvent 356 288  0 0 0 0 0 \n"
"MouseMoveEvent 357 29 0 0 0 0 0 0 \n"
"MouseMoveEvent 358 291  0 0 0 0 0 \n"
"MouseMoveEvent 360 293  0 0 0 0 0 \n"
"MouseMoveEvent 362 295  0 0 0 0 0 \n"
"MouseMoveEvent 363 298  0 0 0 0 0 \n"
"LeaveEvent 341 297 0 0 0 0 0\n"
"ExitEvent 341 297 0 0 0 0 0\n"
;

//----------------------------------------------------------------------------
int TestControlPointsHandleItem(int, char * [])
{
  // Set up a 2D scene, add an XY chart to it
  vtkNew<vtkContextView> view;
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
  view->GetRenderWindow()->SetSize(400, 300);
  vtkNew<vtkChartXY> chart;
  chart->ForceAxesToBoundsOn();
  chart->SetAutoSize(true);
  chart->SetAutoAxes(false);
  chart->SetHiddenAxisBorder(0);
//  chart->SetActionToButton(vtkChart::PAN, vtkContextMouseEvent::MIDDLE_BUTTON);
//  chart->SetActionToButton(vtkChart::SELECT, vtkContextMouseEvent::RIGHT_BUTTON);
  for (int i = 0; i < 4; ++i)
    {
    chart->GetAxis(i)->SetVisible(true);
    chart->GetAxis(i)->SetNumberOfTicks(0);
    chart->GetAxis(i)->SetBehavior(2);
    chart->GetAxis(i)->SetLabelsVisible(false);
    chart->GetAxis(i)->SetMargins(1,1);
    chart->GetAxis(i)->SetTitle("");
    }

  view->GetScene()->AddItem(chart.GetPointer());

  // Create transfer mapping scalar value to opacity.
  vtkNew<vtkPiecewiseFunction> opacityFunction;
  opacityFunction->AddPoint(0.0, 0.1);
  opacityFunction->AddPoint(0.5,0.5);
  opacityFunction->AddPoint(1.,1.);

  // Create transfer mapping scalar value to color.
  vtkNew<vtkColorTransferFunction> colorTransferFunction;
  colorTransferFunction->SetColorSpaceToHSV();
  colorTransferFunction->HSVWrapOn();
  colorTransferFunction->AddHSVSegment(0.,0.,1.,1.,0.3333,0.3333,1.,1.);
  colorTransferFunction->AddHSVSegment(0.3333,0.3333,1.,1.,0.6666,0.6666,1.,1.);
  colorTransferFunction->AddHSVSegment(0.6666,0.6666,1.,1.,1.,0.,1.,1.);

  colorTransferFunction->Build();

  vtkNew<vtkCompositeTransferFunctionItem> item;
  item->SetColorTransferFunction(colorTransferFunction.GetPointer());
  item->SetOpacityFunction(opacityFunction.GetPointer());
  item->SetMaskAboveCurve(true);
  chart->AddPlot(item.GetPointer());

  vtkNew<vtkCompositeControlPointsItem> controlPoints;
  controlPoints->SetColorTransferFunction(colorTransferFunction.GetPointer());
  controlPoints->SetOpacityFunction(opacityFunction.GetPointer());
  controlPoints->SetEndPointsXMovable(false);
  controlPoints->SetUseOpacityPointHandles(true);
  controlPoints->SetEndPointsRemovable(false);
  chart->AddPlot(controlPoints.GetPointer());

  //Finally render the scene and compare the image to a reference image
  view->GetRenderWindow()->SetMultiSamples(0);

  // recorder to play back previously events
  vtkSmartPointer<vtkInteractorEventRecorder> recorder =
    vtkSmartPointer<vtkInteractorEventRecorder>::New();
  recorder->SetInteractor(view->GetInteractor());
//  recorder->SetKeyPressActivationValue('b');

  recorder->ReadFromInputStringOn();
  recorder->SetInputString(TestControlPointsHandleItemLog);

  view->GetInteractor()->Initialize();
  view->Render();

  recorder->Play();
  // Remove the observers so we can go interactive. Without this the "-I"
  // testing option fails.
  recorder->Off();

  //recorder->SetFileName("record.log");
  //recorder->On();
  //recorder->Record();

  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();

  return EXIT_SUCCESS;
}
