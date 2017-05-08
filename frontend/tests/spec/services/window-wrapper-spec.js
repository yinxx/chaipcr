(function() {
  'use strict'

  describe('Testing WindowWrapper Service', function() {

    describe('On Mobile', function() {

      var windowMock = {
        navigator: {
          userAgent: 'Mozilla/5.0 (iPad; CPU OS 8_0_2 like Mac OS X)\
                      AppleWebKit/60.1.4 (KHTML, like Gecko) Version/8.0\
                      Mobile/12A405 Safari/600.1.4'
        },
        innerWidth: 200
      }

      beforeEach(function() {
        module('ChaiBioTech', function($provide) {
          mockCommonServices($provide)
          $provide.value('$window', windowMock)
        })

        inject(function($injector) {
          this.WindowWrapper = $injector.get('WindowWrapper')
        })
      })

      it('should return width of mobile browser window', function() {
        expect(this.WindowWrapper.width()).toEqual(windowMock.innerWidth)
      })

    })

    describe('On Desktop', function() {

      beforeEach(function() {
        module('ChaiBioTech', function($provide) {
          mockCommonServices($provide)
        })

        inject(function($injector) {
          this.$window = $injector.get('$window')
          this.WindowWrapper = $injector.get('WindowWrapper')
        })
      })

      it('should return width of desktop browser window', function() {
        expect(this.WindowWrapper.width()).toEqual($(this.$window).width())
      })

      it('should have events property', function () {
        expect(this.WindowWrapper.events).toEqual({})
      })

    })

  })

})();
