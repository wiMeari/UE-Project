using UnrealSharp.Attributes;
using UnrealSharp.Core.Attributes;
using UnrealSharp.Interop;
using UnrealSharp.Core.Marshallers;

namespace UnrealSharp.TeamProject;

[UClass, GeneratedType("ProjPlayerController", "UnrealSharp.TeamProject.ProjPlayerController")]
public partial class AProjPlayerController : UnrealSharp.Engine.APlayerController
{
    static readonly IntPtr NativeClassPtr;
    static AProjPlayerController()
    {
        NativeClassPtr = UCoreUObjectExporter.CallGetNativeClassFromName(typeof(AProjPlayerController).GetAssemblyName(), "UnrealSharp.TeamProject", "ProjPlayerController");
        IntPtr PlayerCameraController_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "PlayerCameraController");
        PlayerCameraController_Offset = FPropertyExporter.CallGetPropertyOffset(PlayerCameraController_NativeProperty);
        IntPtr PlayerLocation_NativeProperty = FPropertyExporter.CallGetNativePropertyFromName(NativeClassPtr, "PlayerLocation");
        PlayerLocation_Offset = FPropertyExporter.CallGetPropertyOffset(PlayerLocation_NativeProperty);
    }
    
    static int PlayerCameraController_Offset;
    
    public UnrealSharp.TeamProject.APlayerCameraController PlayerCameraController
    {
        get
        {
            return ObjectMarshaller<UnrealSharp.TeamProject.APlayerCameraController>.FromNative(IntPtr.Add(NativeObject, PlayerCameraController_Offset), 0);
        }
    }
    
    
    static int PlayerLocation_Offset;
    
    public float PlayerLocation
    {
        get
        {
            return BlittableMarshaller<float>.FromNative(IntPtr.Add(NativeObject, PlayerLocation_Offset), 0);
        }
    }
    
    
}