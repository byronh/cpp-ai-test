#pragma once


namespace sf {
    class RenderWindow;
}

namespace cdx {


    class Application {

    public:
        static Application& getInstance();
        ~Application() {};

        void setWindow(sf::RenderWindow* window);
        void exit();

    private:
        Application() {};
        Application(const Application& other);
        void operator=(const Application& other);

        sf::RenderWindow* mWindow;
    };


    class ApplicationListener {

    public:
        ApplicationListener() {};
        virtual ~ApplicationListener() {};

        virtual void run() final;

        virtual void onInitialize() = 0;
        virtual void onPause() = 0;
        virtual void onResume() = 0;
        virtual void onUpdate(float delta) = 0;
        virtual void onRender() = 0;
        virtual void onShutdown() = 0;

    public:

        const char* title;
        unsigned int width;
        unsigned int height;

    };

    void runApplication(ApplicationListener* listener);
}
