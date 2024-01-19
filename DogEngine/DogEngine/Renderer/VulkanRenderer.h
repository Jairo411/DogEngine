#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H
class VulkanRenderer
{
	public:
		VulkanRenderer();
		~VulkanRenderer();

		void OnCreate();
		void OnDestroy();


		int ScreenHeight;
		int ScreenWidth;
};
#endif // !VULKANRENDERER_H