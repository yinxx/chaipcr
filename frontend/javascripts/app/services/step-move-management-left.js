/*
 * Chai PCR - Software platform for Open qPCR and Chai's Real-Time PCR instruments.
 * For more information visit http://www.chaibio.com
 *
 * Copyright 2016 Chai Biotechnologies Inc. <info@chaibio.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

window.ChaiBioTech.ngApp.service('StepMovementLeftService', [
    'StepPositionService',
    function(StepPositionService) {
        
        return {

            ifOverLeftSide: function(stepIndicator) {
                stepIndicator.movedStepIndex = null;
                StepPositionService.allPositions.some(this.ifOverLeftSideCallback, stepIndicator);
                return stepIndicator.movedStepIndex;
            },

            ifOverLeftSideCallback: function(points, index) {

                if((this.movement.left + this.leftOffset) > points[0] && (this.movement.left + this.leftOffset) < points[1]) {
                
                    if(this.currentMoveLeft !== index) {
                        this.kanvas.allStepViews[index].moveToSide("right");
                        this.currentMoveLeft = this.movedStepIndex = index;
                        StepPositionService.getPositionObject(this.kanvas.allStepViews);
                    }
                return true;
                }
            }
        };
    }
]);
