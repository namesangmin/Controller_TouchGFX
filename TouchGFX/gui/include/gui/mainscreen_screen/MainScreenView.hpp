#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    virtual ~MainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();


    /// 추가 ///
    //void calculateRange(messageBuffer& msg);
    void updateADCGauge(uint16_t base, uint16_t inner, uint16_t outer);
    void updateJOYGauge(uint16_t joyButton, uint16_t joyX, uint16_t joyY);
    void updateTextMessage(const char* textMsg);

protected:
};

#endif // MAINSCREENVIEW_HPP
